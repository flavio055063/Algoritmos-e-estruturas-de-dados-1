typedef struct cadastro* Lista;

//Para alocar e liberar espaço na memória 
Lista* criarlista();
int liberarlista(Lista *li);

//Para cadastrar novo cliente
void cadastrarcliente(Lista *li, char nome[15], char snome[15], int idade, char email[30], char sexo[10], char telef[15]);

//Para buscar cliente
void buscar(Lista *li, int a, int m, int c, char nome[15], char snome[15], int idade, char email[30], char sexo[10], char telef[15]);

//Opções
void op1(Lista *li, int a, char nome[15], char snome[15], int idade, char email[30], char sexo[10], char telef[15]);
void op2(Lista *li, int m);
void op3(Lista *li, int ok, int m);

//Para imprimir a lista 
void imprimirlista(Lista *li);
