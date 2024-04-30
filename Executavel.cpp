#include <iostream>
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
void Leitura_cidade(struct Cidade cidade[],int &cont){
    int i = 0;
    cout << "\n\nLeitura de Cidades"<<endl;
	for (int saida = 1; i < t && saida != 0; i++){
		cout << "Codigo da Cidade: ";
        cin >> cidade[i].codigo;
        cin.ignore();
        if (cidade[i].codigo > 0){
            cout << "Nome: ";
            getline(cin,cidade[i].nome);
            cout << "UF: ";
            getline(cin,cidade[i].uf);
        }
        else saida = 0;
    }
    cont = i-1;
}
void Leitura_curso(struct Curso curso[],int &cont){
    int i = 0;
	cout << "\n\nLeitura de Cursos"<<endl;
	for(int saida = 1; i < t && saida != 0; i++){
        cout<<"Codigo do Curso: ";
        cin>>curso[i].codigo;
        cin.ignore();
        if(curso[i].codigo > 0){
        	cout<<"Descricao: ";
        	getline(cin,curso[i].descricao);
        	cout<<"Valor por aula: ";
        	cin>>curso[i].valor_por_aula;
		}
    	else {
			saida = 0;
			cout<<"Codigo Invalido ";
		}

    }
    cont = i-1;
}

void Busca_instrutor (struct Cidade v[], int cod){
    int i = 0, f = t;
    int m = (i + f) / 2;
    for (; f >= i && cod != v[m].codigo; m = (i + f) / 2){
        if (cod > v[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == v[m].codigo){
		cout<<"Cidade: "<<v[m].nome<<"---"<<v[m].uf<<endl;	
    }
    else cout<<"Cidade nao encontrada"<<endl;
}

void Leitura_instrutor(struct Instrutor inst[], struct Cidade vetorCidade[], int &cont){
	int i = 0;

	cout << "\n\nLeitura de Instrutores"<<endl;
	for(int saida = 1; i < t && saida != 0; i++){
        cout<<"Codigo do Instrutor: ";
        cin>>inst[i].codigo;
        cin.ignore();
        if(inst[i].codigo > 0){
        	cout<<"Nome: ";
        	getline(cin,inst[i].nome);
        	cout<<"Endereco: ";
			getline(cin,inst[i].endereco);
				int cd = 0;
				cout<<"Codigo cidade: ";
				int codcidade;
				cin>>codcidade;
				inst[i].codigo_cidade = codcidade;
				Busca_instrutor(vetorCidade,codcidade);
				//if(Busca_instrutor(vetorCidade,codcidade) > 0){
				//cd=Busca_instrutor(vetorCidade,codcidade);
				
				//}
				//else{
					//cout<<"Codigo Cidade Invalido";
				//}				
		}
		else{
			saida = 0;
			cout<<"Codigo Invalido ";
		}
	}
    cont = i-1;
}

void inclusao_instrutor (struct Instrutor S[], int contS, struct Instrutor T[], int contT, struct Instrutor A[], int &contA){
    int i = 0, j = 0, k = 0;

	for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].codigo_cidade = S[i].codigo_cidade;
            i++;
            }
        else {
            A[k].codigo = T[j].codigo;
            A[k].nome = T[j].nome;
            A[k].endereco = T[j].endereco;
            A[k].codigo_cidade = T[j].codigo_cidade;
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].endereco = S[i].endereco;
		A[k].codigo_cidade = T[j].codigo_cidade;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].nome = T[j].nome;
        A[k].endereco = T[j].endereco;
        A[k].codigo_cidade = T[j].codigo_cidade;
        j++;
        k++;
    }
    contA = k;
}

void inclusao_Alunos (struct Aluno S[], int contS, struct Aluno T[], int contT, struct Aluno A[], int &contA){
    int i = 0, j = 0, k = 0;

	for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].codigo_cidade = S[i].codigo_cidade;
            i++;
            }
        else {
            A[k].codigo = T[j].codigo;
            A[k].nome = T[j].nome;
            A[k].endereco = T[j].endereco;
            A[k].codigo_cidade = T[j].codigo_cidade;
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].endereco = S[i].endereco;
		A[k].codigo_cidade = T[j].codigo_cidade;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].nome = T[j].nome;
        A[k].endereco = T[j].endereco;
        A[k].codigo_cidade = T[j].codigo_cidade;
        j++;
        k++;
    }
    contA = k;
}

int main(){
	int n = 0;
	int invalido;
	Cidade v[t];
	
	do{
		cout<<"MENU LEITURAS" <<endl;
		cout<<"1 - Cidade"<<endl;
		cout<<"2 - Curso"<<endl;
		cout<<"3 - Instrutor"<<endl;
		cout<<"4 - Inclusao instrutor"<<endl;
		cin>>n;
		invalido=9;
		
		switch(n){
			case 1:{
				int contcidade=0;
				Leitura_cidade(v,contcidade);
				break;
			}
				
			case 2:{
				Curso vcurso[t];
				int contcurso=0;
				Leitura_curso(vcurso,contcurso);
				break;
			}
		
			case 3:{
				Instrutor vinstrutor[t];
				int continstrutor=0;
				Leitura_instrutor(vinstrutor,v,continstrutor);
				break;
			}
			case 4:{
				 struct Instrutor arqS[t], arqT[t], arqA[t];
   				 int contS, contT, contA;
    			cout << "\n\nLeitura do Arquivo S";
    			Leitura_instrutor (arqS,v,contS);
    			cout << "\n\nLeitura do Arquivo T";
    			Leitura_instrutor(arqT,v,contT);
    			inclusao_instrutor (arqS, contS, arqT, contT, arqA, contA);
    			cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
   				 for (int i = 0; i < contA; i++){
       			 cout << "\nCodigo: " << A[i].codigo;
        		cout << "\tNome: " << A[i].nome;
        		cout << "\tEndereco: " << A[i].endereco;
        		cout << "\tCidade: " << A[i].cidade;
        		cout << "\tUF: " << A[i].uf;
				break;
			}
			
			default:{
				cout<<"Opção inválida\n"<<endl;
        		invalido= 9;
				break;
			}
		}
	
	}	while(invalido);
	
}
