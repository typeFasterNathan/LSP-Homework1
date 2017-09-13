// Author:  Keith Shomper
// Date:    9/1/2016
// Purpose: Data structures for first HW assignment emphazising the following
//          C language concepts:
//          - C structures, including nested structures, unions and bit fields
//          - C-style I/O, including binary I/O with fread() and fwrite()
//          - Strict adherence to the C language:  final .c files must compile
//            without warnings using gcc without compatibility flags

struct hd_type {
   unsigned int type :  1;
   unsigned int nam1 :  5;
   unsigned int nam2 :  5;
   unsigned int oper :  3;
   unsigned int pad1 :  2;
   unsigned int pad2 : 16;
};

struct id_type {
   int          n1;
   int          n2;
};

struct fd_type {
   float        n1;
   float        n2;
};

typedef struct hd_type HeaderData ;
typedef struct id_type IntData    ;
typedef struct fd_type FloatData  ;

struct pd_type {
   HeaderData   h;
   union {
      IntData   i;
      FloatData f;
   };
};

typedef struct pd_type ProblemData;

