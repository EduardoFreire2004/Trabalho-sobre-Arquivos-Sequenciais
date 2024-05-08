#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

#define z 10

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
    int codigo_cidade;
};

struct Aluno{
    int codigo;
    string nome;
    string endereco;
    int codigo_cidade;
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
	cout << "\n\n Leitura de Cidades"<<endl;
    
	for (int saida = 1; i < z && saida != 0; i++){
		cout<<" --------------------------"<<endl;
		cout << " Codigo da Cidade: ";
        cin >> cidade[i].codigo;
        cin.ignore();
        if (cidade[i].codigo > 0){
            cout<<" --------------------------"<<endl;
			cout << " Nome: ";
            getline(cin,cidade[i].nome);
           	cout<<" --------------------------"<<endl;
		    cout << " UF: ";
            getline(cin,cidade[i].uf);
        }
        else saida = 0;
    }
    cont = i-1;
}
void Leitura_curso(struct Curso curso[],int &cont){
    int i = 0;
	cout << "\n\n Leitura de Cursos"<<endl;
	for(int saida = 1; i < z && saida != 0; i++){
        cout<<" --------------------------"<<endl;
		cout<<" Codigo do Curso: ";
        cin>>curso[i].codigo;
        cin.ignore();
        if(curso[i].codigo > 0){
        	cout<<" --------------------------"<<endl;
			cout<<" Descricao: ";
        	getline(cin,curso[i].descricao);
        	cout<<" --------------------------"<<endl;
			cout<<" Valor por aula: ";
        	cin>>curso[i].valor_por_aula;
		}
    	
    }
    cont = i-1;
}

int Busca_cidade (struct Cidade v[], int cod,int cont){
    int i = 0,  f=cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != v[m].codigo; m = (i + f) / 2){
        if (cod > v[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == v[m].codigo){
		return m;
    }
    else return -1;
}

bool Busca_instrutor (struct Instrutor v[], int cod,int cont){
    int i = 0, f = cont -1 ;
    int m = (i + f) / 2;
    for (; f >= i && cod != v[m].codigo; m = (i + f) / 2){
        if (cod > v[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if( f != -1){
    	if (cod == v[m].codigo){
		return false;
    	}
    	else return true ;
	}
	else return true;

}

void Leitura_instrutor(struct Instrutor inst[],struct Cidade vetorCidade[], int &cont,int contCidade){
	int i = 0,x=0;
    int buscaR = 0;
	cout << "\n\n Leitura de Instrutores"<<endl;
	for(int saida = 1; i < z && saida != 0; i++){	
		for(int x=1;x != -1;){
		 cout<<" --------------------------"<<endl;
		 cout<<" Codigo do Instrutor: ";
        cin>>inst[i].codigo;
       
        cin.ignore();
		if(inst[i].codigo > 0){
        	
			if(Busca_instrutor(inst,inst[i].codigo,i) == true){
				cout<<" --------------------------"<<endl;
				cout<<" Nome: ";
        		getline(cin,inst[i].nome);
        		cout<<" --------------------------"<<endl;
				cout<<" Endereco: ";
				getline(cin,inst[i].endereco);
            	for(;x != -1;){
					cout<<" --------------------------"<<endl;
					cout<<" Codigo cidade: ";
					cin>>inst[i].codigo_cidade;
                	cin.ignore();
					if(Busca_cidade(vetorCidade,inst[i].codigo_cidade,contCidade) != -1){
                    	buscaR=Busca_cidade(vetorCidade,inst[i].codigo_cidade,contCidade);
                    	cout<<" --------------------------"<<endl;
						cout<<" Cidade: "<<vetorCidade[buscaR].nome<<"-"<<vetorCidade[buscaR].uf<<endl;
                    	x=-1;
					}

					else{
						cout<<"\n ***Codigo Cidade Invalido***"<<endl;
					}
            	}
			}
			else {
				cout<<"\n ***Codigo ja existente*** "<<endl;
				
			}
		}
		else{
				saida = 0;
				cout<<"\n ***Codigo Invalido*** "<<endl;
				x= -1;
			}		
		}
	}
    cont = i-1;
}

bool Busca_instrutor_inclusao (struct Instrutor v[], int cod,int cont){
    
   	int i = 0,  f=cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != v[m].codigo; m = (i + f) / 2){
        if (cod > v[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == v[m].codigo){
		return false;
    }
    else return true;
}
	
void Leitura_instrutor_inclusao(struct Instrutor inst[],struct Cidade vetorCidade[],struct Instrutor instV[],int contV, int &cont,int contCidade){
	int i = 0,x=0;
    int buscaR = 0;
	cout << "\n\n Leitura de Instrutores"<<endl;
	for(int saida = 1; i < z && saida != 0; i++){	
		for(int x=1;x != -1;){
		 cout<<" --------------------------"<<endl;
		 cout<<" Codigo do Instrutor: ";
        cin>>inst[i].codigo;
       
        cin.ignore();
		if(inst[i].codigo > 0){
        	
			if(Busca_instrutor_inclusao(instV,inst[i].codigo,contV) == true){
				cout<<" --------------------------"<<endl;
				cout<<" Nome: ";
        		getline(cin,inst[i].nome);
        		cout<<" --------------------------"<<endl;
				cout<<" Endereco: ";
				getline(cin,inst[i].endereco);
            	for(;x != -1;){
					cout<<" --------------------------"<<endl;
					cout<<" Codigo cidade: ";
					cin>>inst[i].codigo_cidade;
                	cin.ignore();
					if(Busca_cidade(vetorCidade,inst[i].codigo_cidade,contCidade) != -1){
                    	buscaR=Busca_cidade(vetorCidade,inst[i].codigo_cidade,contCidade);
                    	cout<<" --------------------------"<<endl;
						cout<<" Cidade: "<<vetorCidade[buscaR].nome<<"-"<<vetorCidade[buscaR].uf<<endl;
                    	x=-1;
					}

					else{
						cout<<"\n ***Codigo Cidade Invalido***"<<endl;
					}
            	}
			}
			else {
				cout<<"\n ***Codigo ja existente*** "<<endl;
				
			}
		}
		else{
				saida = 0;
				cout<<"\n ***Codigo Invalido*** "<<endl;
				x= -1;
			}		
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

int Busca_aluno (struct Aluno v[], int cod,int cont){
    int i = 0, f = cont -1 ;
    int m = (i + f) / 2;
    for (; f >= i && cod != v[m].codigo; m = (i + f) / 2){
        if (cod > v[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if( f != -1){
    	if (cod == v[m].codigo){
		return false;
    	}
    	else return true ;
	}
	else return true;

}

void Leitura_aluno(struct Aluno aluno[], struct Cidade vetorCidade[], int &cont,int contCidade){
	int i = 0,x=0;
    int buscaR = 0;
	cout << "\n\n Leitura de Alunos"<<endl;
	for(int saida = 1; i < z && saida != 0; i++){	
		for(int x=1;x != -1;){
		cout<<" --------------------------"<<endl;
		cout<<" Codigo do Aluno: ";
        cin>>aluno[i].codigo;
        cin.ignore();
		if(aluno[i].codigo > 0){
			
			if(Busca_aluno(aluno,aluno[i].codigo,i) == true){
				cout<<" --------------------------"<<endl;
				cout<<" Nome: ";
        		getline(cin,aluno[i].nome);
        		cout<<" --------------------------"<<endl;
				cout<<" Endereco: ";
				getline(cin,aluno[i].endereco);
            	for(;x != -1;){
					cout<<" --------------------------"<<endl;
					cout<<" Codigo cidade: ";
					cin>>aluno[i].codigo_cidade;
                	cin.ignore();
					if(Busca_cidade(vetorCidade,aluno[i].codigo_cidade,contCidade) != -1){
                    	buscaR=Busca_cidade(vetorCidade,aluno[i].codigo_cidade,contCidade);
                    	cout<<" --------------------------"<<endl;
						cout<<" Cidade: "<<vetorCidade[buscaR].nome<<"-"<<vetorCidade[buscaR].uf<<endl;
                    	x=-1;
					}

					else{
						cout<<"\n ***Codigo Cidade Invalido***"<<endl;
					}
            	}
			}
			else {
				cout<<"\n ***Codigo ja existente*** "<<endl;
			}
			
		
		}
		else{
				saida = 0;
				cout<<"\n ***Codigo Invalido*** "<<endl;
				x= -1;
			}		
		}
	}
    cont = i-1;
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

void exclusao_alunos (struct Aluno S[], int contS, int T[], int contT, struct Aluno A[], int &contA){
    int i = 0, j = 0, k = 0; 
    for (;j < contT; i++){
        if (S[i].codigo != T[j]){
            A[k].codigo = S[i].codigo;
            A[k].nome = S[i].nome;
            A[k].endereco = S[i].endereco;
            A[k].codigo_cidade = S[i].codigo_cidade;
            k++;
            }
        else {
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].nome = S[i].nome;
        A[k].endereco = S[i].endereco;
        A[k].codigo_cidade = S[i].codigo_cidade;
        i++;
        k++;
    }
    contA = k;
}

void mostrar (struct Instrutor A[], int contA){
    cout << "\n\nLista dos Registros no Arquivo Atualizado" << endl;
    for (int i = 0; i < contA; i++){
        cout << "\nCodigo: " << A[i].codigo;
        cout << "\tNome: " << A[i].nome;
        cout << "\tEndereco: " << A[i].endereco;
        cout << "\tCidade: " << A[i].codigo_cidade;
        cout<<"\n\n"<<endl;
    }
    
}

int main(){
	int n = 0;
	int invalido;
	Cidade cidadeV[z];
    int contCidade=0;
	Instrutor instrutorV[z];
	int contInstrutor=0;
	struct Instrutor arqS[z], arqT[z], arqA[z];
   	int contS, contT, contA;
	do{
		cout<<" ________________________"<<endl;
		cout<<"| MENU LEITURAS 	 |" <<endl;
		cout<<"| 1 - Cidade		 |"<<endl;
		cout<<"| 2 - Curso		 |"<<endl;
		cout<<"| 3 - Instrutor		 |"<<endl;
		cout<<"| 4 - ALUNO 		 |"<<endl;
		cout<<"| 5 - Inclusao instrutor |"<<endl;
		cout<<"|________________________|"<<endl;
		cout<<"\nDigite a instrucao: ";
		cin>>n;
		system("cls");
		
		invalido=9;

		switch(n){
			case 1:{
				Leitura_cidade(cidadeV,contCidade);
				break;
			}

			case 2:{
				Curso cursoV[z];
				int contCurso=0;
				Leitura_curso(cursoV,contCurso);
				break;
			}

			
			case 3:{
				Leitura_instrutor(instrutorV,cidadeV,contInstrutor,contCidade);
				break;
			}
			
			case 4:{
				Aluno Valuno[z];
				int contAluno=0;
				Leitura_aluno(Valuno,cidadeV,contAluno,contCidade);
				break;
			}
			
			case 5:{	
    		
				cout << "\n\nLeitura do Arquivo T";
    			Leitura_instrutor_inclusao (arqT,cidadeV,instrutorV,contInstrutor,contT,contCidade);
    			inclusao_instrutor (instrutorV,contInstrutor, arqT, contT, arqA, contA);
   				mostrar(arqA,contA);
				break;
            }
			

			default:{
				cout<<"Opção inválida\n"<<endl;
        		invalido= 9;
				break;
			}
		}
	
	}while(invalido);

}
