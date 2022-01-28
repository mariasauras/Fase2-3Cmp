/*
*         Maria Sauras Fernandez
*   Second part of Minijulia Compiler
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
  sym_value_type st;
}

/* Identifiers, variables and types */
%token <st.value_data.sense_valor> ASSIGN ENDLINE
%token <st.value_data.enter> INTEGER
%token <st> ID
%token <st.value_data.real> FLOAT
%token <st.value_data.ident> STRING

/* Arithmetical operators */
%token  SUMA RESTA MUL DIV MOD POW 

/* Symbols */
%token OP CP OC CC PC SPACE COMMA FP_D

/* Funcions and Procedures*/
%token END DDP RETURN FUNC

%type <st> programa
%type <st> valor
%type <st> sumrest mullist powlist
%type <st> matrix row  matrix_value 

%type <st> func_header
%type <st> parameters
%type <st> func_call
%type <st> func_return


/* Declarations */
%type main
%type function
%type sentences_list
%type sentence
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
                                                                emet(NULL,0,NULL,"RETURN",NULL);
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

main : start_program sentences_list

start_program : { emet(NULL, 0, NULL, "START main", NULL); }                               

sentences_list : sentences_list sentence
               | sentence


sentence : ID ASSIGN sumrest ENDLINE  {

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

                          }else if (type == MATRIX_TYPE){
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

                          $3.value_type = ID_TYPE;
                          sym_enter($1.value_data.ident.lexema, &$3);
                        }
                      | sumrest ENDLINE  { 

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
                           emet(NULL,0,NULL,"RETURN",&$2);
                          }

/* Priority Hierarchy */


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
