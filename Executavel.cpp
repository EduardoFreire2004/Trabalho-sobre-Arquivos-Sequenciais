#include <iostream>]
#include <string.h>
#include <conio.h>
using namespace std;

#define t 2

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
    cout << "\n\nLeitura de Cidades\n";
	for (int saida = 1; i < t && saida != 0; i++){
		cout << "\nCodigo da Cidade: ";
        cin >> cidade[i].codigo;
        cin.ignore();
        if (cidade[i].codigo != 0){
            cout << "Nome: ";
            getline(cin,cidade[i].nome);
            cout << "UF: ";
            getline(cin,cidade[i].uf);
        }
        else saida = 0;
    }
    cont = i-1;
}
void Leitura_Curso(struct Curso curso[],int &cont){
    int i = 0;
	cout << "\n\nLeitura de Cursos\n";
	for(int saida = 1; i < t && saida != 0; i++){
        cout<<"Codigo do Curso: ";
        cin>>curso[i].codigo;
        cin.ignore();
        if(curso[i].codigo != 0 && curso[i] > 0){
        	cout<<"Descricao: ";
        	getline(cin,curso[i].descricao);
        	cout<<"Valor por aula: ";
        	getline(cin,curso[i].valor_por_aula);	
		}
    	else {
			saida = 0
			cout<<"Codigo Invalido ";	
		}
					
    }
    cont = i-1;
}

void Leitura_instrutor(struct instrutor inst[], struct cidade vetorCidades[], int &cont){
	int i = 0;

	cout << "\n\nLeitura de Instrutores\n";
	for(int saida = 1; i < t && saida != 0; i++){
        cout<<"Codigo do Instrutor: ";
        cin>>inst[i].codigo;
        cin.ignore();
        if(inst[i].codigo != 0 && inst[i] > 0){
        	cout<<"Nome: ";
        	getline(cin,ins[i].nome);
        	cout<<"Endereco: ";
        	getline(cin,inst[i].endereco);
			
			for(int p=0;p != 1){
				cout << "Codigo da Cidade: ";
				cin >> ins[i].codigoCidade;
				
				int j = 0, f = t-1;
    			int m = (j + f) / 2;
    			
				for (; f >= j && m > 0 && inst[i].codigo_cidade != vetorCidade[m].codigo; m = (j + f) / 2){
        			if (inst[i].codigo_cidade > vetorCidade[m].codigo){
						i = m + 1;
					}	
        			else{
						f = m - 1;
					}	
   				}
				   
				if(inst[i].codigoCidade == vetorCidades[m].codigo){
					cout << "Cidade: " << vetorCidades[m].nome << ">>" << vetorCidades[m].uf << endl;
					y=1;	
				}
				
				else{
					cout << "\nCidade invalida!\n";	
				}						   	
			}			
		}	
		
		else{
			saida = 0;
			cout<<"Codigo Invalido ";	
		}			
	}
    cont = i-1;	
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
