/*
*         Maria Sauras Fernandez
*       Stage 3 of Minijulia Compiler
*        Sintactical class (BISON)
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include "symtab.h"
#define MAX_NUM 50
extern FILE *yyout;
extern int yylineno;
extern int yylex();
/*extern void yyerror(char*);*/

/*Array to save the 3AC code*/

char* instructions_buffer[1000];

/* Control Var to generated line number of the instruction and temporally variables*/
unsigned long ln_inst = 1;
unsigned long tmp_cnt = 0;

%}

%code requires {
  /* Les definicions que s'utilitzen al %union han d'estar aqui */
  #include "symtab.h"
  #include "exemple_dades.h"
  #include "exemple_funcions.h"
  
}

%union{
  cond_list cl;
}

/* Identifiers, variables and types */
%token <cl.st.value_data.sense_valor> ASSIGN ENDLINE
%token <cl.st.value_data.enter> INTEGER
%token <cl.st> ID
%token <cl.st.value_data.real> FLOAT
%token <cl.st.value_data.ident> STRING
%token <cl.st.value_data.boolean> BOOLEAN

/* Arithmetical operators */
%token  SUMA RESTA MUL DIV MOD POW 

/* Symbols */
%token OP CP OC CC PC SPACE COMMA OR AND NOT

/* Funcions and Procedures*/
%token END DDP RETURN FUNC DP

/* Relational Operators */
%token GREATERTHAN LESSTHAN GREATEREQ LESSEQ EQ DIF 

/* Control structures tokens */
%token FOR IF ELSE ELSEIF IN WHILE

%type <cl.st> programa
%type <cl.st> valor
%type <cl.st> sumrest mullist powlist
%type <cl.st> matrix row  matrix_value 

%type <cl.st> func_header
%type <cl.st> parameters
%type <cl.st> func_call
%type <cl.st> func_return

%type <cl> bool_value orlist andlist beta gamma
%type <cl> sentences_list sentence if_sentence elseif elsee while_sentence for_sentence
%type <cl.st.value_data.enter> alpha
%type <cl.st.value_data.ident.lexema> rel_op


/* Declarations */
%type main
%type function
%type start_program


%start programa

%%

programa : function_declaration main {
                                      emet(NULL,0,NULL,"HALT",NULL);
                                      emet(NULL,0,NULL,"END",NULL);

                                      for(int i=0; i<ln_inst-1; i++){
                                        fprintf(yyout,"%s\n",instructions_buffer[i]);
                                        free(instructions_buffer[i]);
                                      }
}

function_declaration : function_declaration function {
                                                      for(int i=0; i<ln_inst-1; i++){
                                                        fprintf(yyout,"%s\n",instructions_buffer[i]);
                                                        free(instructions_buffer[i]);
                                                      }
                                                      ln_inst = 1;
                                                      tmp_cnt = 0;                                                 
                                                     }
                     |

function : FUNC func_header ENDLINE sentences_list END ENDLINE {
                                                                emet(NULL,0,NULL,"END\n",NULL);
                                                                pop_scope();
                                                                sym_enter($2.value_data.ident.lexema, &$2);
                                                               }



parameters : parameters COMMA ID DDP ID   { $$.value_data.cont_params += 1; treat_parameter($3,$5); }
           | ID DDP ID                    { $$.value_data.cont_params = 1; treat_parameter($1,$3); }
           |                              { $$.value_data.cont_params = 0; }
            

func_header : ID push OP parameters CP func_return {
                                    
                                    if($6.value_data.return_type != UNKNOWN_TYPE)
                                      treat_return(&$1, $6);
                                    else 
                                      $1.value_data.return_type = UNKNOWN_TYPE;
                                    
                                    emet(NULL,0,NULL,"START",&$1);
                                    $1.value_type = FUNCTION; /* El valor tipo de ID es FUNCTION */
                                    $1.value_data.cont_params = $4.value_data.cont_params;
                                    $$ = $1;
                                    
                                  }
push : { push_scope(); }

func_return : DDP ID              { $$ = $2;}
            |                     { $$.value_data.return_type = UNKNOWN_TYPE; }        

main : start_program sentences_list { complete($2.lls, ln_inst); }

start_program : { emet(NULL, 0, NULL, "START main", NULL); }                               

sentences_list : sentences_list alpha sentence {
                  complete($1.lls, $2);
                  $$.lls = $3.lls;
                }
               | sentence


sentence : if_sentence
          | while_sentence
          | for_sentence
          | ID ASSIGN sumrest ENDLINE  {
                          $$.lls = createEmptyList(); 
                          type type;
                          bool temp_type = false;

                          if($3.value_type == TMP_TYPE){
                            type = $3.value_data.tmp_type;
                            temp_type = true;
                          } else type = $3.value_type;

                          if(type == INT_TYPE){
                            if(temp_type)
                              emet($1.value_data.ident.lexema,$3.value_data.tmp_val,NULL,NULL,NULL);
                            else emet($1.value_data.ident.lexema,0,&$3,NULL,NULL);

                            $3.value_data.id_type = INT_TYPE;
                            
                          } else if(type == FLOAT_TYPE){
                            if(temp_type) emet($1.value_data.ident.lexema,$3.value_data.tmp_val,NULL,NULL,NULL);
                            else emet($1.value_data.ident.lexema,0,&$3,NULL,NULL);

                            $3.value_data.id_type = FLOAT_TYPE;

                          } else if(type == BOOL_TYPE){
                            emet($1.value_data.ident.lexema,0,&$3,NULL,NULL);

                            $3.value_data.id_type = BOOL_TYPE;

                          } else if (type == MATRIX_TYPE){
                              $3.value_data.id_type = MATRIX_TYPE;

                              if($3.value_data.matrix_type == INT_TYPE) {
                                long despl = 0;
                                for(int i= 0; i<$3.value_data.row; i++) 
                                  for(int j= 0; j<$3.value_data.column; j++){
                                    $3.value_data.pos = $3.value_data.column*i+j;
                                    $3.value_data.despl = despl;
                                    if(temp_type){
                                      char buffer_matrix[50];
                                      sprintf(buffer_matrix,"$t%ld",$3.value_data.tmp_val);
                                      emet(buffer_matrix,0,&$3,NULL,NULL);

                                    }else
                                      emet($1.value_data.ident.lexema,0,&$3,NULL,NULL);
                                    despl+=4;
                                  }
                            } else if($3.value_data.matrix_type == FLOAT_TYPE) {
                                long despl = 0;
                                for(int i= 0; i<$3.value_data.row; i++) 
                                  for(int j= 0; j<$3.value_data.column; j++){
                                    $3.value_data.pos = $3.value_data.column*i+j;
                                    $3.value_data.despl = despl;
                                    if(temp_type){
                                      char buffer_matrix[50];
                                      sprintf(buffer_matrix,"$t%ld",$3.value_data.tmp_val);
                                      emet(buffer_matrix,0,&$3,NULL,NULL);

                                    }else
                                      emet($1.value_data.ident.lexema,0,&$3,NULL,NULL);
                                    despl +=4;
                                  }
                                  
                            } else yyerror("Only accept Integer or Float matrix");

                          } else if (type == FUNCTION){
                            $3.value_data.id_type = FUNCTION;
                          } 

                          $3.value_data.ident.lexema = $1.value_data.ident.lexema;
                          $3.value_type = ID_TYPE;
                          sym_enter($1.value_data.ident.lexema, &$3);
                        }
                      | sumrest ENDLINE  { 
                          $$.lls = createEmptyList(); 
                          type valueType;                     
                        
                          if($1.value_type == TMP_TYPE){
                            valueType = $1.value_data.tmp_type;
                          } else valueType = $1.value_type;

                          sym_value_type add_param;
                          add_param.value_type = INT_TYPE;
                          add_param.value_data.enter = 1;
                          
                          if(valueType == INT_TYPE){
                            emet(NULL,0,NULL,"PARAM",&$1);
                            emet(NULL,0,NULL,"PUTI,",&add_param);

                          } else if(valueType == FLOAT_TYPE){
                            emet(NULL,0,NULL,"PARAM",&$1);
                            emet(NULL,0,NULL,"PUTF,",&add_param);
                            
                          } else if(valueType == FUNCTION){
                            $1.value_data.id_type = FUNCTION;
                            
                          } else if(valueType == ID_TYPE){
                            emet(NULL,0,NULL,"PARAM",&$1);
                            if($1.value_data.id_type == INT_TYPE)
                              emet(NULL,0,NULL,"PUTI,",&add_param);
                            else
                              emet(NULL,0,NULL,"PUTF,",&add_param);
                            
                          } else yyerror("AQUI HAY UN ERROR"); 
                        }
                        | RETURN sumrest ENDLINE {   
                            $$.lls = createEmptyList();                
                           emet(NULL,0,NULL,"RETURN",&$2);
                          }

/* Priority Hierarchy */

bool_value : sumrest rel_op sumrest {
                                      $$.llc = createList(ln_inst);
                                      $$.llf = createList(ln_inst+1);
                                      if_emet(&$1,$2,&$3,0);
                                      goto_emet(0);
                                    }
           | OP bool_value CP       { $$ = $2; }

orlist : orlist OR alpha andlist  {
                                    $$.llc = fusion($1.llc,$4.llc);
                                    $$.llf = $4.llf;
                                    complete($1.llf,$3); 
                                  }
      | andlist

andlist : andlist AND alpha bool_value {
                                        complete($1.llc, $3);
                                        $$.llc = $4.llc;
                                        $$.llf = fusion($1.llf,$4.llf);
                                      }
        | NOT bool_value              {
                                        $$.llc = $2.llf;
                                        $$.llf = $2.llc;
                                      } 
        | bool_value

beta :                              {
                                      $$.lls = createList(ln_inst);
                                      goto_emet(0);
                                    }

alpha :                             { $$ = ln_inst; }

if_sentence : IF orlist ENDLINE alpha sentences_list beta alpha elseif alpha elsee END ENDLINE
                                                                              {
                                                                                  complete($2.llc, $4);
                                                                                  complete($2.llf, $7);
                                                                                  complete($8.llf, $9);
                                                                                  list fusiona = fusion($10.lls,$6.lls);
                                                                                  $$.lls = fusion($8.lls,fusiona);
                                                                              }

elseif : elseif ELSEIF alpha orlist ENDLINE alpha sentences_list beta
                                                                        {
                                                                          complete($4.llc, $6);
                                                                          complete($1.llf, $3);
                                                                          $$.llf = $4.llf;
                                                                          list fusiona = fusion($7.lls, $8.lls);
                                                                          $$.lls = fusion(fusiona,$1.lls);
                                                                        }
        |                                                               { $$.lls = createEmptyList(); }

elsee : ELSE ENDLINE alpha sentences_list    { $$.lls = $4.lls; } 
     |                                      { $$.lls = createEmptyList(); }

while_sentence : WHILE alpha orlist ENDLINE alpha sentences_list END ENDLINE
                                                                          {
                                                                            complete($3.llc, $5);
                                                                            complete($6.lls, $2);
                                                                            goto_emet($2);
                                                                            $$.lls = $3.llf;
                                                                          }

for_sentence : gamma sentences_list END ENDLINE {
                                                  complete($2.lls,ln_inst);
                                                  emet($1.st.value_data.ident.lexema,$2.st.value_data.tmp_val,NULL,NULL,NULL);
                                                  sym_value_type aux;
                                                  sum_op(&aux, $1.st,$1.inc);
                                                  goto_emet($1.ln);
                                                  $$.lls = $1.lls;
                                                }

gamma : FOR ID IN sumrest DP sumrest DP sumrest ENDLINE {
                                                          error_treatment(&$4,&$6,&$8);
                                                          emet($2.value_data.ident.lexema, 0,&$4, NULL,NULL);
                                                          $2.value_data.id_type = INT_TYPE;
                                                          $2.value_type = ID_TYPE;
                                                          saveInto($2.value_data.ident.lexema,&$2);
                                                          $$.inc = $6;
                                                          $$.st = $2;
                                                          $$.ln = ln_inst;
                                                          if_emet(&$2,"LE",&$8,ln_inst+2);
                                                          $$.lls = createList(ln_inst);
                                                          goto_emet(0);
                                                        }
      | FOR ID IN sumrest DP sumrest ENDLINE            {
                                                          error_treatment(&$4,&$6,NULL);
                                                          emet($2.value_data.ident.lexema, 0,&$4, NULL,NULL);
                                                          $2.value_data.id_type = INT_TYPE;
                                                          $2.value_type = ID_TYPE;
                                                          saveInto($2.value_data.ident.lexema,&$2);
                                                          sym_value_type aux;
                                                          aux.value_data.enter = 1;
                                                          aux.value_type = INT_TYPE;
                                                          $$.inc = aux;
                                                          $$.st = $2;
                                                          $$.ln = ln_inst;
                                                          if_emet(&$2,"LE",&$6,ln_inst+2);
                                                          $$.lls = createList(ln_inst);
                                                          goto_emet(0);
                                                        }

rel_op : GREATERTHAN            { $$ = "GT";  }
       | GREATEREQ              { $$ = "GE";  }
       | LESSTHAN               { $$ = "LT";  }
       | LESSEQ                 { $$ = "LE";  }
       | EQ                     { $$ = "EQ";  }
       | DIF                    { $$ = "NEQ"; }
       | NOT                    { $$ = "NOT"; }

matrix_value : FLOAT    { $$.value_type = FLOAT_TYPE; $$.value_data.real = $1;  }
             | INTEGER  { $$.value_type = INT_TYPE; $$.value_data.enter = $1; }
 

matrix : matrix PC row          { row_value(&$$,$1,$3); }
       | row                    { $$.value_data.row = 1; }

row : row SPACE matrix_value    { col_value(&$$,$1,$3); }
    | matrix_value              { col_ini(&$$, $1);}

sumrest : sumrest SUMA mullist  { sum_op(&$$,$1,$3); }
        | sumrest RESTA mullist { rest_op(&$$,$1,$3); }
        | mullist

mullist : mullist MUL powlist { mul_op(&$$,$1,$3); } 
        | mullist DIV powlist { div_op(&$$,$1,$3); }
        | mullist MOD powlist { mod_op(&$$,$1,$3); }
        | powlist

powlist : powlist POW valor { pow_op(&$$,$1,$3); }
        | valor

valor : FLOAT                                { $$.value_type = FLOAT_TYPE; $$.value_data.real = $1; }
      | INTEGER                              { $$.value_type = INT_TYPE; $$.value_data.enter = $1; }
      | OP sumrest CP                        { $$ = $2; }
      | ID                                   { if(sym_lookup($1.value_data.ident.lexema, &$$) == SYMTAB_NOT_FOUND) yyerror("Var doesn't exit"); }
      | OC matrix CC                         { $$ = $2; }
      | ID OC sumrest CC                     { acces_vector(&$$, $1.value_data.ident.lexema, $3); }
      | ID OC sumrest COMMA sumrest CC       { acces_matrix(&$$, $1.value_data.ident.lexema, $3, $5); } 
      | ID OP func_call CP                   {
                                                if(sym_lookup($1.value_data.ident.lexema, &$$) == SYMTAB_NOT_FOUND) yyerror("Var doesn't exit");
                                                if($$.value_type == FUNCTION){

                                                  if($$.value_data.cont_params < $3.value_data.cont_params) yyerror("Too much parameters.");
                                                  if($$.value_data.cont_params > $3.value_data.cont_params) yyerror("Not enough parameters.");

                                                  if($$.value_data.return_type != UNKNOWN_TYPE){
                                                    $$.value_data.tmp_type = $$.value_data.return_type;
                                                    long tmp = getTmp();
                                                    emet(NULL,tmp,NULL,"CALL",&$$);
                                                    $$.value_data.tmp_val = tmp;
                                                    $$.value_type = TMP_TYPE;
                                                  }else{
                                                    emet(NULL,0,NULL,"CALL",&$$);
                                                  }
                                                }else yyerror("Only work with function type");
      }

func_call : func_call COMMA sumrest         { $$.value_data.cont_params+= 1; emet(NULL,0,NULL,"PARAM",&$3); } 
          | sumrest                         { $$.value_data.cont_params = 1; emet(NULL,0,NULL,"PARAM",&$1); } 
          |                                 { $$.value_data.cont_params = 0; }                
               

%%
