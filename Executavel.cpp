#include <iostream>]
#include <string.h>
#include <conio.h>
using namespace std;

struct Cidade{
    int codigo;
    string nome;
    string uf;
};

struct Curso{
    int codigo;
    string descricao;
    float valor_por_aula;
};

struct Instrutor{
    int codigo;
    string nome;
    string endereco;
    string codigo_cidade;
};

struct Aluno{
    int codigo;
    string nome;
    string endereco;
    string codigo_cidade;
};

struct Turma{
    int codigo;
    int codigo_curso;
    int codigo_instrutor;
    int total_participantes;
    int quant_max_participantes;
};

struct Matricula{
    int codigo;
    int codigo_aluno;
    int codigo_turma;
    int quantidade_aulas;
    int valor_total;
};
//1
void Leitura_Cidade(struct Cidade cidade[],int &cont){
    int i = 0;
    for (int saida = 1; i < 10 && saida != 0; i++){
		cout << "\nCodigo da Cidade: ";
        cin >> cidade[i].codigo;
        if (cidade[i].codigo != 0){
            cout << "Nome: ";
            cin >> cidade[i].nome;
            cout << "UF: ";
            cin >> cidade[i].uf;
        }
        else saida = 0;
    }
    cont = i-1;
}
void Leitura_Curso(struct Curso curso[],int &cont){
    int i = 0;
	for(int saida = 1; i < 10 && saida != 0; i++){
        cout<<"Codigo do Curso: ";
        cin>>curso[i].codigo;
        if(curso[i].codigo != 0 && curso[i] > 0){
        	cout<<"Descricao: ";
        	cin>>curso[i].descricao;
        	cout<<"Valor por aula: ";
        	cin>>curso[i].valor_por_aula;	
		}
    	else {
			saida = 0
			cout<<"Codigo Invalido ";	
		}
					
    }
    cont = i-1;
}
//2

void buscaserial_instrutor (struct Instrutor inst[], struct Cidade cidade[],int cod){
    int i = 0;
    for (; i < 10 && cod > inst[i].codigo_cidade; i++);
    if (cod == inst[i].codigo_cidade){
		cout << "\tNome: " << cidade[i].nome;
        cout << "\tEndereco: " << cidade[i].endereco;
        cout << "\tCidade: " << inst[i].cidade;
        cout << "\tEstado: " << inst[i].uf;
    }
    else
        cout << "\n\n Cliente nao Encontrado";
    getch();
}


void Leitura_instrutor(struct Instrutor inst[],int &cont){
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCodigo do Instrutor " << (i+1) << ": ";
        cin >> inst[i].codigo;
        if (inst[i].codigo != 0 && inst[i].codigo > 1){
            cout << "Nome: ";
            cin >> inst[i].nome;
            cout << "Endereco: ";
            cin >> inst[i].endereco;
            if(inst[i].codigo_cidade !=0 && inst[i].codigo_cidade > 0){
            	cout << "Codigo Cidade: ";
            	cin >> inst[i].codigo_cidade;
            	
			}
            
        }
        
        else {
			saida = 0
			cout<<"Codigo Invalido ";	
		}
    }
    cont = i-1;
}
	
	
}

void inclusao_instrutor (struct instrutor S[], int contS, struct instrutor T[], int contT, struct instrutor A[], int &contA){
    int i = 0, j = 0, k = 0; 
    
	for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            strcpy (A[k].nome,S[i].nome);
            strcpy (A[k].endereco,S[i].endereco);
            strcpy (A[k].codigo_cidade,S[i].codigo_cidade);
            i++;
            }
        else {
            A[k].codigo = T[j].codigo;
            strcpy (A[k].nome,T[j].nome);
            strcpy (A[k].endereco,T[j].endereco);
            strcpy (A[k].codigo_cidade,T[j].codigo_cidade);
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
        strcpy (A[k].nome,S[i].nome);
        strcpy (A[k].endereco,S[i].endereco);
		strcpy (A[k].codigo_cidade,T[j].codigo_cidade);
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        strcpy (A[k].nome,T[j].nome);
        strcpy (A[k].endereco,T[j].endereco);
        strcpy (A[k].codigo_cidade,T[j].codigo_cidade);
        j++;
        k++;
    }
    contA = k;
}





