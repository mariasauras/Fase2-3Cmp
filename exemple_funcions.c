#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "exemple_funcions.h" 
#define MAX_INS 50

extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;


extern char* instructions_buffer[1000];
extern unsigned long ln_inst;
extern unsigned long tmp_cnt;

/*********************************************************************/
/*                   Funciones FLEX                                  */
/*********************************************************************/

int init_analisi_lexica(char *filename)
{
  int error;
  yyin = fopen(filename,"r");
  if(yyin == NULL) {
    error = EXIT_FAILURE;
  } else {
    error = EXIT_SUCCESS;
  }
  return error;
}

int end_analisi_lexica()
{
  int error;
  error = fclose(yyin);
  if (error == 0) {
    error = EXIT_SUCCESS;
  } else {
    error = EXIT_FAILURE;
  }
  return error;
}

int init_analisi_sintactica(char* filename)
{
  int error = EXIT_SUCCESS;
  yyout = fopen(filename,"w");
  if (yyout == NULL) {
    error = EXIT_FAILURE;
  }
  return error;
}

int end_analisi_sintactica(void)
{
  int error;

  error = fclose(yyout);

  if(error == 0) {
    error = EXIT_SUCCESS;
  } else {
    error = EXIT_FAILURE;
  }
  return error;
}

int analisi_semantica(void)
{
  int error;

  if (yyparse() == 0) {
    error =  EXIT_SUCCESS;
  } else {
    error =  EXIT_FAILURE;
  }
  return error;
}


void yyerror(char *explanation)
{
  fprintf(stderr, "Error: %s , in line %d\n", explanation, yylineno);
  exit(1);
}

/**********************************************************************/
/*                  ARITHMETICAL FUNCTIONS                            */
/**********************************************************************/


void sum_op(sym_value_type * val, sym_value_type v1, sym_value_type v2){

 /*                          DIRECT CASE                                 */
  if (v1.value_type == INT_TYPE && v2.value_type == INT_TYPE){
    (*val).value_type = INT_TYPE;
    (*val).value_data.enter = v1.value_data.enter + v2.value_data.enter;

  } else if(v1.value_type == INT_TYPE && v2.value_type == FLOAT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.enter + v2.value_data.real;

  } else if(v1.value_type == FLOAT_TYPE && v2.value_type == INT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.real + v2.value_data.enter;
    
  } else if (v1.value_type == FLOAT_TYPE && v2.value_type == FLOAT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.real + v2.value_data.real;
  } else {
  /*                         INDIRECT CASE                                 */
    type x, y;
    unsigned long tmp;
    char sum_buffer[10];
    sprintf(sum_buffer,"%s","ADDF");
    (*val).value_data.tmp_type= FLOAT_TYPE;

  
    /* Tipo de valor de las variables x e y*/
    getType(&x,&y,v1,v2);
    
    /* Realizamos los catings y una vez hechos o si no hace falta hacer casting, hacemos la suma.*/
    if(x == FLOAT_TYPE && y == INT_TYPE){
      tmp = getTmp();
      emet(NULL, tmp, NULL, "I2F", &v2);
      v2.value_type = TMP_TYPE;
      v2.value_data.tmp_val = tmp;

    } else if (x == INT_TYPE && y == FLOAT_TYPE){
      tmp = getTmp();
      emet(NULL, tmp, NULL, "I2F", &v1);
      v1.value_type = TMP_TYPE;
      v1.value_data.tmp_val = tmp;

    } else if(x == INT_TYPE && y == INT_TYPE){
      sprintf(sum_buffer,"%s","ADDI");
      (*val).value_data.tmp_type = INT_TYPE;
    }
      

     else if(x != FLOAT_TYPE && y != FLOAT_TYPE) 
       yyerror("Can't operate with these values");
    
    
    tmp = getTmp();
    emet(NULL, tmp, &v1, sum_buffer, &v2);
    (*val).value_type = TMP_TYPE;
    (*val).value_data.tmp_val = tmp; 
  }
}

void rest_op(sym_value_type * val, sym_value_type v1, sym_value_type v2){

  /*                          DIRECT CASE                                 */
  if (v1.value_type == INT_TYPE && v2.value_type == INT_TYPE){
    (*val).value_type = INT_TYPE;
    (*val).value_data.enter = v1.value_data.enter - v2.value_data.enter;

  } else if(v1.value_type == INT_TYPE && v2.value_type == FLOAT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.enter - v2.value_data.real;

  } else if(v1.value_type == FLOAT_TYPE && v2.value_type == INT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.real - v2.value_data.enter;
    
  } else if (v1.value_type == FLOAT_TYPE && v2.value_type == FLOAT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.real - v2.value_data.real;
  } else {
  /*                         INDIRECT CASE                                 */
    type x, y;
    unsigned long tmp;
    char sum_buffer[10];
    sprintf(sum_buffer,"%s","SUBF");
    (*val).value_data.tmp_type= FLOAT_TYPE;
  
    /* Tipo de valor de las variables x e y*/
    getType(&x,&y,v1,v2);
    

    if(x == FLOAT_TYPE && y == INT_TYPE){
      tmp = getTmp();
      emet(NULL, tmp, NULL, "I2F", &v2);
      v2.value_type = TMP_TYPE;
      v2.value_data.tmp_val = tmp;

    } else if (x == INT_TYPE && y == FLOAT_TYPE){
      tmp = getTmp();
      emet(NULL, tmp, NULL, "I2F", &v1);
      v1.value_type = TMP_TYPE;
      v1.value_data.tmp_val = tmp;

    } else if(x == INT_TYPE && y == INT_TYPE){
      (*val).value_data.tmp_type= INT_TYPE;
      sprintf(sum_buffer,"%s","SUBI");
    } else if(x != FLOAT_TYPE && y != FLOAT_TYPE) 
       yyerror("Can't operate with these values");
    
    
    tmp = getTmp();
    emet(NULL, tmp, &v1, sum_buffer, &v2);
    (*val).value_type = TMP_TYPE;
    (*val).value_data.tmp_val = tmp; 
  }
}

void mul_op(sym_value_type * val, sym_value_type v1, sym_value_type v2){

  /*                          DIRECT CASE                                 */
  if (v1.value_type == INT_TYPE && v2.value_type == INT_TYPE){
    (*val).value_type = INT_TYPE;
    (*val).value_data.enter = v1.value_data.enter * v2.value_data.enter;

  } else if(v1.value_type == INT_TYPE && v2.value_type == FLOAT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.enter * v2.value_data.real;

  } else if(v1.value_type == FLOAT_TYPE && v2.value_type == INT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.real * v2.value_data.enter;
    
  } else if (v1.value_type == FLOAT_TYPE && v2.value_type == FLOAT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.real * v2.value_data.real;
  } else {
  /*                         INDIRECT CASE                                 */
    type x, y;
    unsigned long tmp;
    char sum_buffer[10];
    sprintf(sum_buffer,"%s","MULF");
     (*val).value_data.tmp_type= FLOAT_TYPE;
    
  
    /* Tipo de valor de las variables x e y*/
    getType(&x,&y,v1,v2);
    

    if(x == FLOAT_TYPE && y == INT_TYPE){
      tmp = getTmp();
      emet(NULL, tmp, NULL, "I2F", &v2);
      v2.value_type = TMP_TYPE;
      v2.value_data.tmp_val = tmp;

    } else if (x == INT_TYPE && y == FLOAT_TYPE){
      tmp = getTmp();
      emet(NULL, tmp, NULL, "I2F", &v1);
      v1.value_type = TMP_TYPE;
      v1.value_data.tmp_val = tmp;

    } else if(x == INT_TYPE && y == INT_TYPE){
      sprintf(sum_buffer,"%s","MULI");
      (*val).value_data.tmp_type= INT_TYPE;

    } else if(x != FLOAT_TYPE && y != FLOAT_TYPE) 
       yyerror("Can't operate with these values");
    
    
    tmp = getTmp();
    emet(NULL, tmp, &v1, sum_buffer, &v2);
    (*val).value_type = TMP_TYPE;
    (*val).value_data.tmp_val = tmp; 
  }
  
}

void div_op(sym_value_type * val, sym_value_type v1, sym_value_type v2){
  /*                          DIRECT CASE                                 */
  if (v1.value_type == INT_TYPE && v2.value_type == INT_TYPE){
    (*val).value_type = INT_TYPE;
    (*val).value_data.enter = v1.value_data.enter / v2.value_data.enter;

  } else if(v1.value_type == INT_TYPE && v2.value_type == FLOAT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.enter / v2.value_data.real;

  } else if(v1.value_type == FLOAT_TYPE && v2.value_type == INT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.real / v2.value_data.enter;
    
  } else if (v1.value_type == FLOAT_TYPE && v2.value_type == FLOAT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = v1.value_data.real / v2.value_data.real;
  } else {
  /*                         INDIRECT CASE                                 */
    type x, y;
    unsigned long tmp;
    char sum_buffer[10];
    sprintf(sum_buffer,"%s","DIVF");
     (*val).value_data.tmp_type= FLOAT_TYPE;
  
    /* Tipo de valor de las variables x e y*/
    getType(&x,&y,v1,v2);
    

    if(x == FLOAT_TYPE && y == INT_TYPE){
      tmp = getTmp();
      emet(NULL, tmp, NULL, "I2F", &v2);
      v2.value_type = TMP_TYPE;
      v2.value_data.tmp_val = tmp;

    } else if (x == INT_TYPE && y == FLOAT_TYPE){
      tmp = getTmp();
      emet(NULL, tmp, NULL, "I2F", &v1);
      v1.value_type = TMP_TYPE;
      v1.value_data.tmp_val = tmp;

    } else if(x == INT_TYPE && y == INT_TYPE){
      (*val).value_data.tmp_type= INT_TYPE;
      sprintf(sum_buffer,"%s","DIVI");

    } else if(x != FLOAT_TYPE && y != FLOAT_TYPE) 
       yyerror("Can't operate with these values");
    
    
    tmp = getTmp();
    emet(NULL, tmp, &v1, sum_buffer, &v2);
    (*val).value_type = TMP_TYPE;
    (*val).value_data.tmp_val = tmp; 
  }
 
}

void mod_op(sym_value_type * val, sym_value_type v1, sym_value_type v2){

  if(v1.value_type == INT_TYPE && v2.value_type == INT_TYPE ){
    (*val).value_type = INT_TYPE;
    (*val).value_data.enter = v1.value_data.enter % v2.value_data.enter;
  } else{

    /*                         INDIRECT CASE                                 */
    type x, y;
    unsigned long tmp;
    char mod_buffer[10];
    sprintf(mod_buffer,"%s","MOD");
    (*val).value_data.tmp_type= FLOAT_TYPE;
  
    /* Tipo de valor de las variables x e y*/
    getType(&x,&y,v1,v2);
    

    if(x == INT_TYPE && y == INT_TYPE){
    
      tmp = getTmp();
      emet(NULL, tmp, &v1, mod_buffer, &v2);
      (*val).value_type = TMP_TYPE;
       (*val).value_data.tmp_type= INT_TYPE;
      (*val).value_data.tmp_val = tmp;

    } else yyerror("Can't operate with these type of values.");


  }
  

}

void pow_op(sym_value_type * val, sym_value_type v1, sym_value_type v2){

  if (v1.value_type == INT_TYPE && v2.value_type == INT_TYPE){
    (*val).value_type = INT_TYPE;
    (*val).value_data.enter = pow(v1.value_data.enter,v2.value_data.enter);  
  } else if(v1.value_type == INT_TYPE && v2.value_type == FLOAT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = pow(v1.value_data.enter,v2.value_data.real);
  } else if(v1.value_type == FLOAT_TYPE && v2.value_type == INT_TYPE){
      (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = pow(v1.value_data.real,v2.value_data.enter);
  } else if (v1.value_type == FLOAT_TYPE && v2.value_type == FLOAT_TYPE){
    (*val).value_type = FLOAT_TYPE;
    (*val).value_data.real = pow(v1.value_data.real,v2.value_data.real);
  } else {
    /*                         INDIRECT CASE                                 */
    type x, y;
    unsigned long tmp;
    char sum_buffer[10];
    sprintf(sum_buffer,"%s","POWF");
     (*val).value_data.tmp_type= FLOAT_TYPE;
  
    /* Tipo de valor de las variables x e y*/
    getType(&x,&y,v1,v2);
    

    if(x == FLOAT_TYPE && y == INT_TYPE){
      tmp = getTmp();
      emet(NULL, tmp, NULL, "I2F", &v2);
      v2.value_type = TMP_TYPE;
      v2.value_data.tmp_val = tmp;

    } else if (x == INT_TYPE && y == FLOAT_TYPE){
      tmp = getTmp();
      emet(NULL, tmp, NULL, "I2F", &v1);
      v1.value_type = TMP_TYPE;
      v1.value_data.tmp_val = tmp;

    } else if(x == INT_TYPE && y == INT_TYPE){
       (*val).value_data.tmp_type= INT_TYPE;
      sprintf(sum_buffer,"%s","POWI");

    } else if(x != FLOAT_TYPE && y != FLOAT_TYPE) 
       yyerror("Can't operate with these values");
    
    
    tmp = getTmp();
    emet(NULL, tmp, &v1, sum_buffer, &v2);
    (*val).value_type = TMP_TYPE;
    (*val).value_data.tmp_val = tmp; 
  }
  
  
}

/*********************************************************************/
/*                 MATRIX&VECTOR FUNCTIONS                           */
/*********************************************************************/

/* Function to inicialize columns */
void col_ini(sym_value_type * matrix, sym_value_type matrix_value){

  (*matrix).value_type = MATRIX_TYPE;
  /* Indico que tipo de valor tendra */
  if(matrix_value.value_type == INT_TYPE){

    (*matrix).value_data.matrix_type = INT_TYPE;

    (*matrix).value_data.integer_matrix = calloc(1, sizeof(long));
    if((*matrix).value_data.integer_matrix == NULL) yyerror("Error. Can't inicialize heap memory");
    (*matrix).value_data.integer_matrix[0] = matrix_value.value_data.enter;

  } else if(matrix_value.value_type == FLOAT_TYPE){
   
    (*matrix).value_data.matrix_type = FLOAT_TYPE;

    (*matrix).value_data.float_matrix = calloc(1, sizeof(float));
     if((*matrix).value_data.float_matrix  == NULL) yyerror("Error. Can't inicialize heap memory");
    (*matrix).value_data.float_matrix[0] = matrix_value.value_data.real;

  } else yyerror(" Matrix only accept Integer or Float.");
  
  (*matrix).value_data.num_elems = 1;
  (*matrix).value_data.column = 1;
  
}

/* Function to inicialice more than one columns */
void col_value(sym_value_type * matrix, sym_value_type v1, sym_value_type v2){
  
  (*matrix).value_type = MATRIX_TYPE;

  if(v2.value_type == INT_TYPE){

    (*matrix).value_data.matrix_type = INT_TYPE;

    (*matrix).value_data.integer_matrix = calloc(v1.value_data.column+1, sizeof(long));
    if((*matrix).value_data.integer_matrix  == NULL) yyerror("Error. Can't inicialize heap memory");

    for(int i = 0; i < v1.value_data.column; i++) 
      (*matrix).value_data.integer_matrix[i] = v1.value_data.integer_matrix[i];
    
    free(v1.value_data.integer_matrix);

    (*matrix).value_data.integer_matrix[v1.value_data.column] = v2.value_data.enter;

  } else if(v2.value_type == FLOAT_TYPE){
    /* Indico que tipo de valor tendra */
    (*matrix).value_data.matrix_type = FLOAT_TYPE;
    (*matrix).value_data.float_matrix = calloc(v1.value_data.column+1, sizeof(float));
    if((*matrix).value_data.float_matrix  == NULL) yyerror("Error. Can't inicialize heap memory");

    for(int i = 0; i < v1.value_data.column; i++) 
      (*matrix).value_data.float_matrix[i] = v1.value_data.float_matrix[i];
    
    free(v1.value_data.float_matrix);

    (*matrix).value_data.float_matrix[v1.value_data.column] = v2.value_data.real;

  } else yyerror(" Matrix only accept Integer or Float.");
  
  (*matrix).value_data.column=v1.value_data.column+1;
  (*matrix).value_data.num_elems++;
}

/* Function for using vectors and matrices with more than one line */
void row_value(sym_value_type *matrix, sym_value_type v1, sym_value_type v2){

  (*matrix).value_type = MATRIX_TYPE;
  
  
  if(v1.value_data.column != v2.value_data.column) yyerror("Error. Incompatible dimension: Different size of columns in matrix");

  /* Type of vectors and matrices: 
   1. INT TYPE
   2. FLOAT TYPE
   3. INT TYPE AND FLOAT TYPE
   4. FLOAT TYPE AND INT TYPE */

  if(v1.value_data.matrix_type == INT_TYPE && v2.value_data.matrix_type == INT_TYPE){
    (*matrix).value_data.matrix_type = INT_TYPE;

    (*matrix).value_data.integer_matrix = calloc(v1.value_data.num_elems+v2.value_data.num_elems, sizeof(long));
    if((*matrix).value_data.integer_matrix  == NULL) yyerror("Error. Can't inicialize heap memory");

    /* Copy the content of first row (V1) in the final matrix */
    for(int i=0; i<v1.value_data.num_elems; i++) (*matrix).value_data.integer_matrix[i] = v1.value_data.integer_matrix[i];

    /* Copy the content of second row (V2) in the final matrix.
        In ths part of the code we treat this if V2 was the second row but not it's not necessarily 
        the second line it may be the fourth (for example).  */
    int j = 0;
    for(int i = v1.value_data.num_elems ; i<v2.value_data.column+v1.value_data.num_elems; i++){
      (*matrix).value_data.integer_matrix[i] = v2.value_data.integer_matrix[j];
      j++;
    }

    /* free the heap memory of the V1 and v2*/
    free(v1.value_data.integer_matrix);
    free(v2.value_data.integer_matrix);
   
  } else if ((v1.value_data.matrix_type == FLOAT_TYPE && v2.value_data.matrix_type == FLOAT_TYPE)){
    (*matrix).value_data.matrix_type = FLOAT_TYPE;

    (*matrix).value_data.float_matrix = calloc(v1.value_data.num_elems+v2.value_data.num_elems, sizeof(float));
    if((*matrix).value_data.float_matrix  == NULL) yyerror("Error. Can't inicialize heap memory");
  
    for(int i=0; i<v1.value_data.num_elems ; i++) (*matrix).value_data.float_matrix[i] = v1.value_data.float_matrix[i];

    int j = 0;
    for(int i = v1.value_data.num_elems ; i<v2.value_data.column+v1.value_data.num_elems; i++){
      (*matrix).value_data.float_matrix[i] = v2.value_data.float_matrix[j];
      j++;
    }

    free(v1.value_data.float_matrix);
    free(v2.value_data.float_matrix);
  } else if ((v1.value_data.matrix_type == INT_TYPE && v2.value_data.matrix_type == FLOAT_TYPE)){
    (*matrix).value_data.matrix_type = FLOAT_TYPE;

    (*matrix).value_data.float_matrix = calloc(v1.value_data.num_elems+v2.value_data.num_elems, sizeof(float));
    if((*matrix).value_data.float_matrix  == NULL) yyerror("Error. Can't inicialize heap memory");
  
    for(int i=0; i<v1.value_data.num_elems ; i++) (*matrix).value_data.float_matrix[i] = (float)v1.value_data.integer_matrix[i];

    int j = 0;
    for(int i = v1.value_data.num_elems ; i<v2.value_data.column+v1.value_data.num_elems; i++){
      (*matrix).value_data.float_matrix[i] = v2.value_data.float_matrix[j];
      j++;
    }

    free(v1.value_data.integer_matrix);
    free(v2.value_data.float_matrix);
  }else if ((v1.value_data.matrix_type == FLOAT_TYPE && v2.value_data.matrix_type == INT_TYPE)){
    (*matrix).value_data.matrix_type = FLOAT_TYPE;

    (*matrix).value_data.float_matrix = calloc(v1.value_data.num_elems+v2.value_data.num_elems, sizeof(float));
    if((*matrix).value_data.float_matrix  == NULL) yyerror("Error. Can't inicialize heap memory");
  
    for(int i=0; i<v1.value_data.num_elems ; i++) (*matrix).value_data.float_matrix[i] = v1.value_data.float_matrix[i];

    int j = 0;
    for(int i = v1.value_data.num_elems ; i<v2.value_data.column+v1.value_data.num_elems; i++){
      (*matrix).value_data.float_matrix[i] = (float)v2.value_data.integer_matrix[j];
      j++;
    }

    free(v2.value_data.integer_matrix);
    free(v1.value_data.float_matrix);
  }else yyerror("INCORRECT VALUE OF MATRIX & VECTOR");

  (*matrix).value_data.row = (*matrix).value_data.row + 1;
  (*matrix).value_data.column = v2.value_data.column;
  (*matrix).value_data.num_elems = (*matrix).value_data.row * (*matrix).value_data.column;

}

/* Function to acces a vector */
void acces_vector(sym_value_type * vector, char * id, sym_value_type valist){

  type t = getTypeV(valist);

  if (t == INT_TYPE){
    
    sym_value_type auxVector;
    if(sym_lookup(id, &auxVector) == SYMTAB_NOT_FOUND) yyerror("Var doesn't exist");

    if(auxVector.value_data.id_type != MATRIX_TYPE) yyerror("Var isn't matrix type");

    if((auxVector.value_data.row > 1 && auxVector.value_data.column != 1)
      || (auxVector.value_data.row != 1 && auxVector.value_data.column > 1)) 
        yyerror("Error: This is a bidimensional vector. You must use Two indexes"); 

    sym_value_type auxiliar;
    auxiliar.value_data.enter = 4;
    auxiliar.value_type = INT_TYPE;
    
    mul_op(&auxVector,valist,auxiliar);
    
    long temp = getTmp();

    auxiliar.value_data.ident.lexema = id;
    auxiliar.value_type = ID_TYPE;

    emet(NULL, temp, &auxiliar, NULL, &auxVector);
    (*vector).value_type = TMP_TYPE;
    (*vector).value_data.tmp_val = temp;

    if((auxVector).value_data.matrix_type == INT_TYPE)
      (*vector).value_data.tmp_type = INT_TYPE;
    else
      (*vector).value_data.tmp_type = FLOAT_TYPE;

  } else yyerror("Integer access must be an integer.");
}

/* Function to acces a matrix */
void acces_matrix(sym_value_type * vector, char * id, sym_value_type v1, sym_value_type v2){


  type t = getTypeV(v1);
  type t2 = getTypeV(v2);

  if (t == INT_TYPE && t2 == INT_TYPE){
    
    sym_value_type auxVector;
    sym_value_type auxVector2;
    if(sym_lookup(id, &auxVector) == SYMTAB_NOT_FOUND) yyerror("Var doesn't exist");

    if(auxVector.value_data.id_type != MATRIX_TYPE) yyerror("Var isn't matrix type");

    if((auxVector.value_data.row == 1 || auxVector.value_data.column == 1)) 
        yyerror("Error: This is a unidimensional vector. You must use one index");

    sym_value_type auxiliar;
    auxiliar.value_data.enter = 4;
    auxiliar.value_type = INT_TYPE;
    
    mul_op(&auxVector,v1,auxiliar);
    sum_op(&auxVector2,auxVector,v2);
    
    long temp = getTmp();

    auxiliar.value_data.ident.lexema = id;
    auxiliar.value_type = ID_TYPE;

    emet(NULL, temp, &auxiliar, NULL, &auxVector2);
    (*vector).value_type = TMP_TYPE;
    (*vector).value_data.tmp_val = temp;

    if((auxVector).value_data.matrix_type == INT_TYPE)
      (*vector).value_data.tmp_type = INT_TYPE;
    else
      (*vector).value_data.tmp_type = FLOAT_TYPE;

  } else yyerror("Integer access must be an integer.");
}

/**********************************************************************/
/*                 BOOLEAN & RELATIONAL FUNCTIONS                     */
/**********************************************************************/



void not_op(sym_value_type * not, sym_value_type v1){

  if(v1.value_type == BOOL_TYPE){
    (*not).value_type = BOOL_TYPE;
    if(v1.value_data.boolean == true){
      (*not).value_data.boolean = false;
    } else (*not).value_data.boolean = true;
  }else yyerror("The NOT operation can only be used with Booleans");
}

void and_op(sym_value_type * and, sym_value_type v1, sym_value_type v2){

  if(v1.value_type == BOOL_TYPE && v2.value_type == BOOL_TYPE){
    (*and).value_type = BOOL_TYPE;
    if(v1.value_data.boolean == true && v2.value_data.boolean == true){
      (*and).value_data.boolean = true;
    } else (*and).value_data.boolean = false;
  }else yyerror("The AND operation can only be used with Booleans");

}

void or_op(sym_value_type * or, sym_value_type v1, sym_value_type v2){

   if(v1.value_type == BOOL_TYPE && v2.value_type == BOOL_TYPE){
    (*or).value_type = BOOL_TYPE;

    if(v1.value_data.boolean == true && v2.value_data.boolean == false){
      (*or).value_data.boolean = true;
    } else if(v1.value_data.boolean == false && v2.value_data.boolean == true){
      (*or).value_data.boolean = true;
    } else if(v1.value_data.boolean == true && v2.value_data.boolean == true){
      (*or).value_data.boolean = true;
    } else (*or).value_data.boolean = false;
    
  } else yyerror("The OR operation can only be used with Booleans");

}

void gt_op(sym_value_type * gt, sym_value_type v1, sym_value_type v2){

  if(v1.value_type == INT_TYPE){

    if(v2.value_type == INT_TYPE){
      (*gt).value_type = BOOL_TYPE;
      if(v1.value_data.enter > v2.value_data.enter) {
        (*gt).value_data.boolean = true;
      } else (*gt).value_data.boolean = false;
    } else if(v2.value_type == FLOAT_TYPE){
      (*gt).value_type = BOOL_TYPE;
      if((float)v1.value_data.enter > v2.value_data.real) {
        (*gt).value_data.boolean = true;
      } else (*gt).value_data.boolean = false;
    } else yyerror("The value can only be integer or float");

  } else if(v1.value_type == FLOAT_TYPE){

    if(v2.value_type == INT_TYPE){
      (*gt).value_type = BOOL_TYPE;
      if(v1.value_data.real > (float)v2.value_data.enter) {
        (*gt).value_data.boolean = true;
      } else (*gt).value_data.boolean = false;
    } else if(v2.value_type == FLOAT_TYPE){
      (*gt).value_type = BOOL_TYPE;
      if(v1.value_data.real > v2.value_data.real) {
        (*gt).value_data.boolean = true;
      } else (*gt).value_data.boolean = false;
    } else yyerror("The value can only be integer or float");

   } else yyerror("The value can only be integer or float");

}

void ge_op(sym_value_type * ge, sym_value_type v1, sym_value_type v2){

  if(v1.value_type == INT_TYPE){
    if(v2.value_type == INT_TYPE){
      (*ge).value_type = BOOL_TYPE;

      if(v1.value_data.enter >= v2.value_data.enter){
        (*ge).value_data.boolean = true;
      } else (*ge).value_data.boolean = false;

    } else if(v2.value_type == FLOAT_TYPE){
      (*ge).value_type = BOOL_TYPE;
      if((float)v1.value_data.enter >= v2.value_data.real){
        (*ge).value_data.boolean = true;
      } else (*ge).value_data.boolean = false;
    } else yyerror("The value can only be integer or float");

  } else if(v1.value_type == FLOAT_TYPE){
    if(v2.value_type == INT_TYPE){
      (*ge).value_type = BOOL_TYPE;

      if(v1.value_data.real >= (float)v2.value_data.enter){
        (*ge).value_data.boolean = true;
      } else (*ge).value_data.boolean = false;

    } else if(v2.value_type == FLOAT_TYPE){
      (*ge).value_type = BOOL_TYPE;
      if((float)v1.value_data.real >= v2.value_data.real){
        (*ge).value_data.boolean = true;
      } else (*ge).value_data.boolean = false;
    } else yyerror("The value can only be integer or float");

  } else yyerror("The value can only be integer or float");

}

void lt_op(sym_value_type * lt, sym_value_type v1, sym_value_type v2){

  if(v1.value_type == INT_TYPE){

    if(v2.value_type == INT_TYPE){
      (*lt).value_type = BOOL_TYPE;
      if(v1.value_data.enter < v2.value_data.enter) {
        (*lt).value_data.boolean = true;
      } else (*lt).value_data.boolean = false;
    } else if(v2.value_type == FLOAT_TYPE){
      (*lt).value_type = BOOL_TYPE;
      if((float)v1.value_data.enter < v2.value_data.real) {
        (*lt).value_data.boolean = true;
      } else (*lt).value_data.boolean = false;
    } else yyerror("The value can only be integer or float");

  } else if(v1.value_type == FLOAT_TYPE){

    if(v2.value_type == INT_TYPE){
      (*lt).value_type = BOOL_TYPE;
      if(v1.value_data.real < (float)v2.value_data.enter) {
        (*lt).value_data.boolean = true;
      } else (*lt).value_data.boolean = false;
    } else if(v2.value_type == FLOAT_TYPE){
      (*lt).value_type = BOOL_TYPE;
      if(v1.value_data.real < v2.value_data.real) {
        (*lt).value_data.boolean = true;
      } else (*lt).value_data.boolean = false;
    } else yyerror("The value can only be integer or float");

   } else yyerror("The value can only be integer or float");

}

void le_op(sym_value_type * le, sym_value_type v1, sym_value_type v2){

  if(v1.value_type == INT_TYPE){

    if(v2.value_type == INT_TYPE){
      (*le).value_type = BOOL_TYPE;
      if(v1.value_data.enter <= v2.value_data.enter) {
        (*le).value_data.boolean = true;
      } else (*le).value_data.boolean = false;
    } else if(v2.value_type == FLOAT_TYPE){
      (*le).value_type = BOOL_TYPE;
      if((float)v1.value_data.enter <= v2.value_data.real) {
        (*le).value_data.boolean = true;
      } else (*le).value_data.boolean = false;
    } else yyerror("The value can only be integer or float");

  } else if(v1.value_type == FLOAT_TYPE){

    if(v2.value_type == INT_TYPE){
      (*le).value_type = BOOL_TYPE;
      if(v1.value_data.real <= (float)v2.value_data.enter) {
        (*le).value_data.boolean = true;
      } else (*le).value_data.boolean = false;
    } else if(v2.value_type == FLOAT_TYPE){
      (*le).value_type = BOOL_TYPE;
      if(v1.value_data.real <= v2.value_data.real) {
        (*le).value_data.boolean = true;
      } else (*le).value_data.boolean = false;
    } else yyerror("The value can only be integer or float");

   } else yyerror("The value can only be integer or float");

}

void eq_op(sym_value_type * eq, sym_value_type v1, sym_value_type v2){

   if(v1.value_type == INT_TYPE && v2.value_type == INT_TYPE){
     (*eq).value_type = BOOL_TYPE;
     if(v1.value_data.enter == v2.value_data.enter){
      (*eq).value_data.boolean = true;
     }else (*eq).value_data.boolean = false;
   } else if(v1.value_type == FLOAT_TYPE && v2.value_type == FLOAT_TYPE){
      (*eq).value_type = BOOL_TYPE;
     if(v1.value_data.real == v2.value_data.real){
       (*eq).value_data.boolean = true;
     }else (*eq).value_data.boolean = false;
   } else if((v1.value_type == FLOAT_TYPE && v2.value_type == INT_TYPE) || (v1.value_type == INT_TYPE && v2.value_type == FLOAT_TYPE)){
     (*eq).value_type = BOOL_TYPE;
     (*eq).value_data.boolean = false;
   } else yyerror("The value can only be integer or float");
}

void dif_op(sym_value_type * dif, sym_value_type v1, sym_value_type v2){

     if(v1.value_type == INT_TYPE && v2.value_type == INT_TYPE){
      (*dif).value_type = BOOL_TYPE;
      if(v1.value_data.enter != v2.value_data.enter){
        (*dif).value_data.boolean = true;
      }else (*dif).value_data.boolean = false;
   } else if(v1.value_type == FLOAT_TYPE && v2.value_type == FLOAT_TYPE){
      (*dif).value_type = BOOL_TYPE;
      if(v1.value_data.real != v2.value_data.real){
        (*dif).value_data.boolean = true;
      }else (*dif).value_data.boolean = false;
   } else if((v1.value_type == FLOAT_TYPE && v2.value_type == INT_TYPE) || (v1.value_type == INT_TYPE && v2.value_type == FLOAT_TYPE)){
      yyerror("ERROR! Both values should be of the same type");
   } else yyerror("The value can only be integer or float");
}


/**********************************************************************/
/*                            C3A  FUNCTIONS                          */
/**********************************************************************/

/* Function to calculte temp variable.*/
unsigned long getTmp(){
  tmp_cnt++;
  return tmp_cnt;
}


/* Función que comprueba el tipo de las variables v1 y v2 y le da valor de tipo a X e Y. */
void getType(type* x, type* y, sym_value_type v1, sym_value_type v2){

  /* CASE V1*/
  if(v1.value_type == TMP_TYPE)
    (*x) = v1.value_data.tmp_type;
  else if (v1.value_type == ID_TYPE)
    (*x) = v1.value_data.id_type;
  else 
    (*x)= v1.value_type;

  /* CASE V2*/
  if(v2.value_type == TMP_TYPE)
    (*y) = v2.value_data.tmp_type;
  else if (v2.value_type == ID_TYPE)
    (*y) = v2.value_data.id_type;
  else 
    (*y)= v2.value_type;

}

type getTypeV(sym_value_type v1){

  /* CASE V1*/
  if(v1.value_type == TMP_TYPE)
    return v1.value_data.tmp_type;
  else if (v1.value_type == ID_TYPE)
    return v1.value_data.id_type;
  else 
    return v1.value_type;


}

/* La función emet genera la instrucción. */
void emet(char* var, unsigned long tmp, sym_value_type* v1, char* op, sym_value_type* v2){

  char* buffer = malloc(MAX_INS*sizeof(char));
  
  if (var == NULL){

    char v1_buff[MAX_INS];

    for(int i=0;i< MAX_INS; i++)
      v1_buff[i]=0;

    if(v1 != NULL){

      if(v1->value_type == INT_TYPE){
        sprintf(v1_buff, "%ld", v1->value_data.enter);
      } else if(v1->value_type == FLOAT_TYPE){
        sprintf(v1_buff, "%f", v1->value_data.real);
      }else if(v1->value_type == TMP_TYPE){
        sprintf(v1_buff, "$t%ld", v1->value_data.tmp_val);
      } else if(v1->value_type == ID_TYPE){
        sprintf(v1_buff, "%s", v1->value_data.ident.lexema);
      }else if(v1->value_type == FUNCTION){
        sprintf(v1_buff, "%s", v1->value_data.ident.lexema);
      }else if(v1->value_type == BOOL_TYPE){
        if(v1->value_data.boolean == 1)
          sprintf(v1_buff, "true");
        else
          sprintf(v1_buff, "false");

      } else if(v1->value_type == MATRIX_TYPE){
        if(v1->value_data.matrix_type == FLOAT_TYPE){
          sprintf(v1_buff, "[%ld] = %f",v1->value_data.despl,v1->value_data.float_matrix[v1->value_data.pos]);
        } else sprintf(v1_buff, "[%ld] = %ld",v1->value_data.despl,v1->value_data.integer_matrix[v1->value_data.pos]); 
      }
    }

    char v2_buff[MAX_INS];

    for(int i=0; i < MAX_INS; i++)
      v2_buff[i]=0;

    if(v2 != NULL){

      if(v2->value_type == INT_TYPE){
        sprintf(v2_buff, "%ld", v2->value_data.enter);
      } else if(v2->value_type == FLOAT_TYPE){
        sprintf(v2_buff, "%f", v2->value_data.real);
      }else if(v2->value_type == TMP_TYPE){
        sprintf(v2_buff, "$t%ld", v2->value_data.tmp_val);
      } else if(v2->value_type == ID_TYPE){
        sprintf(v2_buff, "%s", v2->value_data.ident.lexema);
      } else if(v2->value_type == FUNCTION){
        sprintf(v2_buff, "%s", v2->value_data.ident.lexema);
      } else if(v2->value_type == BOOL_TYPE){
        if(v2->value_data.boolean == 1)
          sprintf(v1_buff, "true");
        else
          sprintf(v1_buff, "false");
      }else if(v2->value_type == MATRIX_TYPE){
        if(v2->value_data.matrix_type == FLOAT_TYPE){
          sprintf(v2_buff, "[%ld] = %f",v2->value_data.despl,v2->value_data.float_matrix[v2->value_data.pos]);
        } else sprintf(v2_buff, "[%ld] = %ld",v2->value_data.despl,v2->value_data.integer_matrix[v2->value_data.pos]); 
      }
    } 

  /* Comprobamos el valor del temporal para hacer el emet*/
    if (tmp != 0)
      if(v1 == NULL)
        sprintf(buffer, "%03ld: $t%ld := %s %s ", ln_inst, tmp, op, v2_buff);
      else if(v2 == NULL)
        sprintf(buffer, "%03ld: $t%ld := %s %s ", ln_inst, tmp, v1_buff, op);
      else if (op == NULL)
        sprintf(buffer, "%03ld: $t%ld := %s[%s]", ln_inst, tmp, v1_buff, v2_buff);
      else
        sprintf(buffer, "%03ld: $t%ld := %s %s %s", ln_inst, tmp, v1_buff, op, v2_buff);
    else
      if(v1 == NULL && v2 == NULL)
        sprintf(buffer, "%03ld: %s ", ln_inst, op);
      else if(v1 == NULL)
        sprintf(buffer, "%03ld: %s %s ", ln_inst, op, v2_buff);
      else if(v2 == NULL)
        sprintf(buffer, "%03ld: %s %s ", ln_inst, v1_buff, op);
      else
        sprintf(buffer, "%03ld: %s %s %s ", ln_inst, v1_buff, op, v2_buff);
    
  }else {
    /* en el caso en que Var != NULL, significará que solo tendremos un operando, es por eso que solo tenemos en cuenta V1.*/
    if(v1 == NULL)
      sprintf(buffer, "%03ld: %s := $t%ld",ln_inst,var,tmp);
    else
      if(v1->value_type == INT_TYPE)
        sprintf(buffer, "%03ld: %s := %ld",ln_inst,var,v1->value_data.enter);
      else if (v1->value_type == FLOAT_TYPE)
        sprintf(buffer, "%03ld: %s := %f",ln_inst,var,v1->value_data.real);
      else if (v1->value_type == BOOL_TYPE)
        if(v1->value_data.boolean == 1)
          sprintf(buffer, "%03ld: %s := true",ln_inst,var);
        else
          sprintf(buffer, "%03ld: %s := false",ln_inst,var);
          
      else if (v1->value_type == TMP_TYPE)
        sprintf(buffer,"%03ld: %s := %ld",ln_inst,var,v1->value_data.tmp_val);
      else if (v1->value_type == MATRIX_TYPE){
        if(v1->value_data.matrix_type == FLOAT_TYPE)
          sprintf(buffer,"%03ld: %s[%ld] := %f ",ln_inst,var,v1->value_data.despl,v1->value_data.float_matrix[v1->value_data.pos]);
        else
          sprintf(buffer,"%03ld: %s[%ld] := %ld ",ln_inst,var,v1->value_data.despl,v1->value_data.integer_matrix[v1->value_data.pos]);
      }  
  }

  instructions_buffer[ln_inst-1] = buffer;
  ln_inst++;
}

/* Función emet para el condicional if */
void if_emet(sym_value_type* v1, char* op,sym_value_type* v2, long dest){
  char* buffer = malloc(MAX_INS*sizeof(char));

  char v1_buff[MAX_INS];
  for(int i=0;i< MAX_INS; i++)
    v1_buff[i]=0;

  if(v1->value_type == INT_TYPE){
    sprintf(v1_buff, "%ld", v1->value_data.enter);
  } else if(v1->value_type == FLOAT_TYPE){
    sprintf(v1_buff, "%f", v1->value_data.real);
  }else if(v1->value_type == TMP_TYPE){
    sprintf(v1_buff, "$t%ld", v1->value_data.tmp_val);
  } else if(v1->value_type == ID_TYPE){
    sprintf(v1_buff, "%s", v1->value_data.ident.lexema);
  }else if(v1->value_type == FUNCTION){
    sprintf(v1_buff, "%s", v1->value_data.ident.lexema);
  } else if(v1->value_type == MATRIX_TYPE){
    if(v1->value_data.matrix_type == FLOAT_TYPE){
      sprintf(v1_buff, "[%ld] = %f",v1->value_data.despl,v1->value_data.float_matrix[v1->value_data.pos]);
    } else sprintf(v1_buff, "[%ld] = %ld",v1->value_data.despl,v1->value_data.integer_matrix[v1->value_data.pos]); 
  }

  char v2_buff[MAX_INS];
  for(int i=0; i < MAX_INS; i++)
    v2_buff[i]=0;

  if(v2 != NULL){
      if(v2->value_type == INT_TYPE){
        sprintf(v2_buff, "%ld", v2->value_data.enter);
      } else if(v2->value_type == FLOAT_TYPE){
        sprintf(v2_buff, "%f", v2->value_data.real);
      }else if(v2->value_type == TMP_TYPE){
        sprintf(v2_buff, "$t%ld", v2->value_data.tmp_val);
      } else if(v2->value_type == ID_TYPE){
        sprintf(v2_buff, "%s", v2->value_data.ident.lexema);
      } else if(v2->value_type == FUNCTION){
        sprintf(v2_buff, "%s", v2->value_data.ident.lexema);
      } else if(v2->value_type == MATRIX_TYPE){
        if(v2->value_data.matrix_type == FLOAT_TYPE){
          sprintf(v2_buff, "[%ld] = %f",v2->value_data.despl,v2->value_data.float_matrix[v2->value_data.pos]);
        } else sprintf(v2_buff, "[%ld] = %ld",v2->value_data.despl,v2->value_data.integer_matrix[v2->value_data.pos]); 
      }
    } 
  
  type t1 = getTypeV(*v1);
  type t2 = getTypeV(*v2);
  if(v2 != NULL){
    if((t1 == BOOL_TYPE && t2 != BOOL_TYPE) || (t2 == BOOL_TYPE && t1 != BOOL_TYPE)) yyerror("Incompatible type in IF");

    if(dest == 0)
      sprintf(buffer,"%03ld: IF %s %s %s GOTO",ln_inst,v1_buff,op,v2_buff);
    else
      sprintf(buffer,"%03ld: IF %s %s %s GOTO %ld",ln_inst,v1_buff,op,v2_buff,dest);
       
  } else{
    if(dest == 0)
      sprintf(buffer, "%03ld: IF %s GOTO", ln_inst,v1_buff);
    else
      sprintf(buffer, "%03ld: IF %s GOTO %ld", ln_inst,v1_buff,dest);
      
  }

  instructions_buffer[ln_inst-1] = buffer;
  ln_inst++;
  
}
/* Función emet para el goto */
void goto_emet(long line_number){
  char buffer[MAX_INS];
  for(int i=0;i>MAX_INS;i++)
    buffer[i]=0;
  
  if(line_number != 0)
    sprintf(buffer,"GOTO %ld", line_number);
  else
    sprintf(buffer,"GOTO");

  emet(NULL,0,NULL,buffer,NULL);
}
/* Función para tratar los parametros de las funciones */
void treat_parameter(sym_value_type v1, sym_value_type val_type){

  if(strcmp(val_type.value_data.ident.lexema, "Int32") == 0)
    v1.value_data.id_type = INT_TYPE;
  else if(strcmp(val_type.value_data.ident.lexema, "Float32") == 0)
    v1.value_data.id_type = FLOAT_TYPE;
  else if(strcmp(val_type.value_data.ident.lexema, "Vector{Int32}") == 0){
    v1.value_data.id_type = MATRIX_TYPE;
    v1.value_data.matrix_type = INT_TYPE;
  }else if(strcmp(val_type.value_data.ident.lexema, "Vector{Float32}") == 0){
    v1.value_data.id_type = MATRIX_TYPE;
    v1.value_data.matrix_type = FLOAT_TYPE;
  } else yyerror("Incorrect Parameter Type.");

  v1.value_type = ID_TYPE;
  /* Guardamos en la tabla de simbolos el valor de ID*/
  sym_enter(v1.value_data.ident.lexema, &v1);

}

/* Función para tratar los parametros de las funciones */
void treat_return(sym_value_type* v1, sym_value_type val_type){

  if(strcmp(val_type.value_data.ident.lexema, "Int32") == 0){
    (*v1).value_data.id_type = INT_TYPE;
    (*v1).value_data.return_type = INT_TYPE;
  } else if(strcmp(val_type.value_data.ident.lexema, "Float32") == 0){
    (*v1).value_data.id_type = FLOAT_TYPE;
    (*v1).value_data.return_type = FLOAT_TYPE;
  } else if(strcmp(val_type.value_data.ident.lexema, "Vector{Int32}") == 0){
    (*v1).value_data.id_type = MATRIX_TYPE;
    (*v1).value_data.matrix_type = INT_TYPE;
  } else if(strcmp(val_type.value_data.ident.lexema, "Vector{Float32}") == 0){
    (*v1).value_data.id_type = MATRIX_TYPE;
    (*v1).value_data.matrix_type = FLOAT_TYPE;
  } else yyerror("Incorrect Parameter Type.");
}

void push_scope(){
  if(sym_push_scope() != SYMTAB_OK) yyerror("Error in push");
}

void pop_scope(){
  if(sym_pop_scope() != SYMTAB_OK) yyerror("Error in pop");
}

/**********************************************************************/
/*                       BACK-PATCHING  FUNCTIONS                     */
/**********************************************************************/


/* Creamos una lista enlazada vacía. */
list createEmptyList(){
  list l;
  l.num_elems = 0;
  l.start_point = NULL;

  return l;
}

/* Inicializamos una lista enlazada */
list createList(long ln){
  list l;
  l.num_elems = 1;

  node* n = (node*)calloc(1,sizeof(n));
  if(n == NULL) yyerror("Error. Can't inicialize heap memory");
  (*n).line_num = ln;
  (*n).next_elem = NULL;

  l.start_point = n;

  return l;
}

/* Añadimos un nuevo elemento a la lista */
void addElem(list* l, long v){
  node* n = l->start_point;

  node* newNode = (node*) calloc(1,sizeof(node));
  if(newNode == NULL) yyerror("Error. Can't inicialize heap memory");

  (*newNode).line_num = v;
  (*newNode).next_elem = NULL;
  if(n == NULL) l->start_point = newNode;
  else{
    while((*n).next_elem != NULL) n = (*n).next_elem;
    (*n).next_elem = newNode;
  }
}

/* Completamos las intrucciones pendientes de completar con la lista indicada: p.ej --> GOTO (Line Number) */
void complete(list l, long v){
  
  char* buffer;
  node* n = l.start_point;

  while(n != NULL){

    buffer = calloc(MAX_INS, sizeof(char));
    if(buffer == NULL) yyerror("Error. Can't inicialize heap memory");

    sprintf(buffer,"%s %ld",instructions_buffer[(*n).line_num-1],v);
    /* Liberamos la memoria que usa la instruccion incompleta */
    free(instructions_buffer[(*n).line_num-1]);

    /* Actualizamos la posición de la intruccion incompleta completandola */
    instructions_buffer[(*n).line_num-1] = buffer;

    /* Miramos el siguiente nodo de la lista (si hay) */
    n = (*n).next_elem;

  }
}

/* Fusionamos dos funciones*/
list fusion(list l, list l2){
  list newList;
  newList = createEmptyList();

  node* n;
  n = l.start_point;
  while(n!= NULL){
    addElem(&newList,(*n).line_num);
    n = (*n).next_elem;
    newList.num_elems +=1;
  }

  n = l2.start_point;
  while(n!= NULL){
    addElem(&newList,(*n).line_num);
    n = (*n).next_elem;
    newList.num_elems +=1;
  }

  return newList;

}


