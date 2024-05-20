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
    float valor_total;
};

int busca_cidade (struct Cidade v[], int cod,int cont){
    int i = 0,  f=cont -1;
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

void leitura_cidade(struct Cidade cidade[],int &cont){
    int i = 0;    
	for (int saida = 1; i < z && saida != 0; i++){
		cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
		cout<<" --------------------------"<<endl;
		cout << " Codigo da Cidade: ";
        cin >> cidade[i].codigo;
        cin.ignore();
		if (cidade[i].codigo > 0){
			cout << " Nome da Cidade: ";
            getline(cin,cidade[i].nome);
		    cout << " UF da Cidade: ";
            getline(cin,cidade[i].uf);
            cout<<" --------------------------"<<endl;
        }
        else saida = 0;
    }
    cont = i-1;
}

int busca_curso (struct Curso v[], int cod,int cont){
	int i = 0,  f=cont -1;
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

void leitura_curso(struct Curso curso[],int &cont){
	int i = 0;
	for(int saida = 1; i < z && saida != 0; i++){
		cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
        cout<<" --------------------------"<<endl;
		cout<<" Codigo do Curso: ";
        cin>>curso[i].codigo;
        cin.ignore();
        if(curso[i].codigo > 0){
			cout<<" Descricao do Curso: ";
        	getline(cin,curso[i].descricao);
			cout<<" Valor por Aula: ";
        	cin>>curso[i].valor_por_aula;
        	cin.ignore();
        	cout<<" --------------------------"<<endl;
		}
		else saida = 0;
    }
    cont = i-1;
}

bool busca_instrutor (struct Instrutor v[], int cod,int cont){
	int i = 0, f = cont -1 ;
	int m = (i + f) / 2;
    for (; f >= i && cod != v[m].codigo; m = (i + f) / 2){
        if (cod > v[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(f != -1){
	
		if (cod == v[m].codigo){
		return false;
    	}
    	else return true ;
	}else return true;
}

int busca_instrutor_turma (struct Instrutor v[], int cod,int cont){
    int i = 0,  f=cont -1;
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

void leitura_instrutor(struct Instrutor inst[],int &cont,struct Cidade vetorCidade[], int contCidade,struct Instrutor instrutor[],int contInstrutor){
	int i = 0;
    int buscaR = 0;
	for(int saida = 1; i < z && saida != 0; i++){	
		for(int x=1;x != -1;){
		 	cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
			cout<<" --------------------------"<<endl;
			cout<<" Codigo do Instrutor: ";
        	cin>>inst[i].codigo;
        	cin.ignore();
			if(inst[i].codigo > 0){
				if(busca_instrutor(inst,inst[i].codigo,i) and busca_instrutor(instrutor,inst[i].codigo,contInstrutor) == true){
					cout<<" Nome do Instutor: ";
        			getline(cin,inst[i].nome);
					cout<<" Endereco do instrutor: ";
					getline(cin,inst[i].endereco);
            		for(;x != -1;){
						cout<<" Codigo da cidade: ";
						cin>>inst[i].codigo_cidade;
                		cin.ignore();
						if(busca_cidade(vetorCidade,inst[i].codigo_cidade,contCidade) != -1){
                    		buscaR=busca_cidade(vetorCidade,inst[i].codigo_cidade,contCidade);
							cout<<" Cidade: "<<vetorCidade[buscaR].nome<<"-"<<vetorCidade[buscaR].uf<<endl;
							cout<<" --------------------------"<<endl;
                    		x=-1;
						}
						else{
							cout<<"\n\n ***Codigo Cidade Invalido***"<<endl;
						}
            		}
				}
				else {
					cout<<"\n\n ***Codigo ja existente*** "<<endl;
				}
			}
			else{
				saida = 0;
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
		A[k].codigo_cidade = S[i].codigo_cidade;
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

bool busca_aluno (struct Aluno v[], int cod,int cont){
	int i = 0, f = cont -1 ;
	int m = (i + f) / 2;
    for (; f >= i && cod != v[m].codigo; m = (i + f) / 2){
        if (cod > v[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(f != -1){
	
		if (cod == v[m].codigo){
		return false;
    	}
    	else return true ;
	}else return true;
}

int busca_aluno_matricula (struct Aluno v[], int cod,int cont){
    int i = 0,  f=cont -1;
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

void leitura_aluno(struct Aluno aluno[],int &cont,struct Cidade vetorCidade[],int contCidade,struct Aluno alunos[],int contAlunos){
	int i = 0,x=0;
    int buscaR = 0;
	for(int saida = 1; i < z && saida != 0; i++){	
		for(int x=1;x != -1;){
		cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
		cout<<" --------------------------"<<endl;
		cout<<" Codigo do Aluno: ";
        cin>>aluno[i].codigo;
        cin.ignore();
		if(aluno[i].codigo > 0){
			if(busca_aluno(aluno,aluno[i].codigo,i) and busca_aluno(alunos,aluno[i].codigo,contAlunos)== true){
				cout<<" Nome: ";
        		getline(cin,aluno[i].nome);
				cout<<" Endereco: ";
				getline(cin,aluno[i].endereco);
            	for(;x != -1;){
					cout<<" Codigo cidade: ";
					cin>>aluno[i].codigo_cidade;
                	cin.ignore();
					if(busca_cidade(vetorCidade,aluno[i].codigo_cidade,contCidade) != -1){
                    	buscaR=busca_cidade(vetorCidade,aluno[i].codigo_cidade,contCidade);
						cout<<" Cidade: "<<vetorCidade[buscaR].nome<<"-"<<vetorCidade[buscaR].uf<<endl;
						cout<<" --------------------------"<<endl;
                    	x=-1;
					}

					else{
						cout<<"\n\n ***Codigo Cidade Invalido***"<<endl;
					}
            	}
			}
			else {
				cout<<"\n\n ***Codigo ja existente*** "<<endl;
			}
			
		}
		else{
				saida = 0;
				x= -1;
			}		
		}
	}
    cont = i-1;
}


void inclusao_aluno (struct Aluno S[], int contS, struct Aluno T[], int contT, struct Aluno A[], int &contA){
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
		A[k].codigo_cidade = S[i].codigo_cidade;
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

void leitura_aluno_exclusao(int TExclusao[], int &contTExclusao){
	int i = 0;
    for (int saida = 1; i < z && saida > 0; i++) {   	
		cout << "Codigo para exclusao: ";
       	cin >> TExclusao[i];
        cin.ignore();
        saida= TExclusao[i];
    }
	if(TExclusao[z-1] != 0){
		if (i == z) {
        contTExclusao = i;
    	}else
        	contTExclusao = i - 1;	
	}else
		contTExclusao = i - 1;
}

int busca_turma (struct Turma v[], int cod,int cont){
    int i = 0,  f=cont -1;
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

void leitura_turmas(struct Turma turma[], int &cont,struct Curso curso[], int contCurso, struct Cidade cidade[], int contCidade, struct Instrutor instrutor[], int contInstrutor){
	int i = 0,x=0;
    int buscaR = 0;
	for(int saida = 1; i < z && saida != 0; i++){	
		for(int x=1;x != -1;){
			cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
			cout<<" --------------------------"<<endl;
			cout<<" Codigo da Turma: ";
        	cin>>turma[i].codigo;
        	cin.ignore();
			if(turma[i].codigo > 0){			
				for(;x != -1;){
					cout<<" Codigo do Curso: ";
					cin>>turma[i].codigo_curso;
                	cin.ignore();
					if(busca_curso(curso,turma[i].codigo_curso,contCurso) != -1){
                    	buscaR=busca_curso(curso,turma[i].codigo_curso,contCurso);
						cout<<" Curso: "<<curso[buscaR].descricao<<endl;
						cout<<" Valor Por Aula: "<<curso[buscaR].valor_por_aula<<endl;
                    	x=-1;
					}
					else{
						cout<<"\n\n ***Codigo Curso Invalido***"<<endl;
					}
            	}
				x=1;
				for(;x != -1;){
					cout<<" Codigo do Instrutor: ";
					cin>>turma[i].codigo_instrutor;
                	cin.ignore();
					if(busca_instrutor_turma(instrutor,turma[i].codigo_instrutor,contInstrutor) != -1){
                    	buscaR=busca_instrutor_turma(instrutor,turma[i].codigo_instrutor,contInstrutor);
						cout<<" Instrutor: "<<instrutor[buscaR].nome<<endl;
						buscaR=busca_cidade(cidade,instrutor[buscaR].codigo_cidade,contCidade);
						cout<<" Cidade: "<<cidade[buscaR].nome<<"-"<<cidade[buscaR].uf<<endl;
                    	x=-1;
					}
					else{
						cout<<"\n\n ***Codigo Instrutor Invalido***"<<endl;
					}
				}
		
				cout<<" Maximo de Participantes: ";
        		cin>>turma[i].quant_max_participantes;
        		x=1;
				for(;x != -1;){
					cout<<" Total de Participantes: ";
        			cin>>turma[i].total_participantes;
					if(turma[i].total_participantes > turma[i].quant_max_participantes){
						cout<<"Quantidade Maxima Ultrapassada"<<endl;
					}
					else{
						x=-1;
						cout<<" --------------------------"<<endl;
					}
				}	
			}	
			else{
				saida = 0;
				x= -1;
			}			
		}
	}    
	cont = i-1;	
}

void inclusao_turma (struct Turma S[], int contS, struct Turma T[], int contT, struct Turma A[], int &contA){
    int i = 0, j = 0, k = 0;
	for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].codigo_curso = S[i].codigo_curso;
            A[k].codigo_instrutor = S[i].codigo_instrutor;
            A[k].total_participantes = S[i].total_participantes;
            A[k].quant_max_participantes = S[i].quant_max_participantes;
            i++;
            }
        else {
            A[k].codigo = T[j].codigo;
            A[k].codigo_curso = T[j].codigo_curso;
            A[k].codigo_instrutor = T[j].codigo_instrutor;
            A[k].total_participantes = T[j].total_participantes;
            A[k].quant_max_participantes = T[j].quant_max_participantes;
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].codigo_curso = S[i].codigo_curso;
        A[k].codigo_instrutor = S[i].codigo_instrutor;
        A[k].total_participantes = S[i].total_participantes;
        A[k].quant_max_participantes = S[i].quant_max_participantes;
        i++;
        k++;
    }
    while (j < contT){
        A[k].codigo = T[j].codigo;
        A[k].codigo_curso = T[j].codigo_curso;
        A[k].codigo_instrutor = T[j].codigo_instrutor;
        A[k].total_participantes = T[j].total_participantes;
        A[k].quant_max_participantes = T[j].quant_max_participantes;
        j++;
        k++;
    }
    contA = k;
}

void leitura_matricula(struct Matricula matricula[], int &cont,struct Aluno aluno[], int contAluno, struct Turma turma[], int contTurma, struct Instrutor instrutor[], int contInstrutor,struct Cidade cidade[],int contCidade,struct Curso curso[],int contCurso){
	int i = 0,x=0;
    int buscaR = 0,buscaC = 0;
    float valorAula = 0;
	for(int saida = 1; i < z && saida != 0; i++){	
		for(int x=1;x != -1;){
			cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
			cout<<" --------------------------"<<endl;
			cout<<" Codigo da Matricula: ";
        	cin>>matricula[i].codigo;
        	cin.ignore();
			if(matricula[i].codigo > 0){			
				for(;x != -1;){
					cout<<" Codigo do Aluno: ";
					cin>>matricula[i].codigo_aluno;
                	cin.ignore();
					if(busca_aluno_matricula(aluno,matricula[i].codigo_aluno,contAluno) != -1){
                    	buscaR=busca_aluno_matricula(aluno,matricula[i].codigo_aluno,contAluno);
						cout<<" Aluno: "<<aluno[buscaR].nome<<endl;
						buscaR=busca_cidade(cidade,aluno[buscaR].codigo_cidade,contCidade);
						cout<<" Cidade: "<<cidade[buscaR].nome << "-" <<cidade[buscaR].uf <<endl;
                    	x=-1;
					}
					else{
						cout<<"\n\n ***Codigo Aluno Invalido***"<<endl;
					}
            	}
				x=1;
				for(;x != -1;){
					cout<<" Codigo da Turma: ";
					cin>>matricula[i].codigo_turma;
                	cin.ignore();
					if(busca_turma(turma,matricula[i].codigo_turma,contTurma) != -1){
                    	buscaR=busca_turma(turma,matricula[i].codigo_turma,contTurma);
						buscaC=busca_curso(curso,turma[buscaR].codigo_curso,contCurso);
						cout<<" Descricao curso: "<<curso[buscaC].descricao<<endl;	
						buscaR=busca_turma(turma,turma[buscaR].codigo_instrutor,contInstrutor);
						cout<<" Instrutor: "<<instrutor[buscaR].nome<<endl;	
						buscaR=busca_turma(turma,matricula[i].codigo_turma,contTurma);
						buscaC=busca_curso(curso,turma[buscaR].codigo_curso,contCurso);
						cout<<" Valor Por Aula: "<<curso[buscaC].valor_por_aula<<endl;
						valorAula = curso[buscaC].valor_por_aula;
                    	x=-1;
					}
					else{
						cout<<"\n\n ***Codigo Turma Invalido***"<<endl;
					}
				}
				cout<<" Quantidade de Aulas: ";
        		cin>>matricula[i].quantidade_aulas;
        		matricula[i].valor_total = matricula[i].quantidade_aulas*valorAula;
				cout<< " Valor total: "<<matricula[i].valor_total<<endl;
				cout<<" --------------------------"<<endl;
        		x= -1;
			}	
			else{
				saida = 0;
				x= -1;
			}			
		}
	}    
	cont = i-1;	
}

void inclusao_matricula (struct Matricula S[], int contS, struct Matricula T[], int contT, struct Matricula A[], int &contA){
    int i = 0, j = 0, k = 0;
	for (;i < contS && j < contT;k++){
        if (S[i].codigo < T[j].codigo){
            A[k].codigo = S[i].codigo;
            A[k].codigo_aluno = S[i].codigo_aluno;
            A[k].codigo_turma = S[i].codigo_turma;
            A[k].quantidade_aulas = S[i].quantidade_aulas;
            A[k].valor_total = S[i].valor_total;
            i++;
            }
        else {
            A[k].codigo = T[j].codigo;
            A[k].codigo_aluno = T[j].codigo_aluno;
            A[k].codigo_turma = T[j].codigo_turma;
            A[k].quantidade_aulas = T[j].quantidade_aulas;
            A[k].valor_total = T[j].valor_total;
            j++;
        }
    }
    while (i < contS){
        A[k].codigo = S[i].codigo;
        A[k].codigo_aluno = S[i].codigo_aluno;
        A[k].codigo_turma = S[i].codigo_turma;
        A[k].quantidade_aulas = S[i].quantidade_aulas;
        A[k].valor_total = S[i].valor_total;
        i++;
        k++;
    }
    while (j < contT){
    	A[k].codigo = T[j].codigo;
    	A[k].codigo_aluno = T[j].codigo_aluno;
    	A[k].codigo_turma = T[j].codigo_turma;
        A[k].quantidade_aulas = T[j].quantidade_aulas;
        A[k].valor_total = T[j].valor_total;
        j++;
        k++;
    }
    contA = k;
}


void mostrar_instrutor (struct Instrutor A[], int contA){
    cout << "\n\n Lista Instrutores" << endl;
    for (int i = 0; i < contA; i++){
        cout << "\nCodigo: " << A[i].codigo;
        cout << "\tNome: " << A[i].nome;
        cout << "\tEndereco: " << A[i].endereco;
        cout << "\tCidade: " << A[i].codigo_cidade;
    }  
}

void mostrar_alunos (struct Aluno A[], int contA){
    cout << "\n\n Registros Alunos" << endl;
    for (int i = 0; i < contA; i++){
        cout << "\n	Codigo: " << A[i].codigo;
        cout << "\t	Nome: " << A[i].nome;
        cout << "\t	Endereco: " << A[i].endereco;
        cout << "\t	Cidade: " << A[i].codigo_cidade;
    }  
}
void mostrar_cidade (struct Cidade A[], int contA){
    cout << "\n\n Registros Cidade" << endl;
    for (int i = 0; i < contA; i++){
       	cout << "\n  Codigo: " << A[i].codigo;
        cout << "\t  Nome: " << A[i].nome;
        cout << "\t  UF: " << A[i].uf;
    }  
}

void mostrar_curso (struct Curso A[], int contA){
    cout << "\n\n Registros Curso" << endl;
    for (int i = 0; i < contA; i++){
       	cout << "\n  Codigo: " << A[i].codigo;
        cout << "\t  Descricao: " << A[i].descricao;
        cout << "\t  Valor por Aula: " << A[i].valor_por_aula;
    }  
}

void mostrar_turma_max (struct Turma turma[], int contTurma,struct Instrutor instrutor[],int contInstrutor,struct Curso curso[],int contCurso,struct Cidade cidade[],int contCidade){
	int buscaT=0;
		 
	 for (int i = 0; i < contTurma; i++){
		 
		 if(turma[i].total_participantes == turma[i].quant_max_participantes){
	 		cout<<"\n Codigo Turma: "<<turma[i].codigo;
			buscaT=busca_turma(turma,turma[i].codigo_curso,contTurma);
			cout<<"\n Curso: "<<curso[buscaT].descricao;
			buscaT=busca_turma(turma,turma[i].codigo_instrutor,contTurma);
			cout<<"\t Instrutor: "<<instrutor[buscaT].nome;
			buscaT=busca_instrutor_turma(instrutor,instrutor[buscaT].codigo_cidade,contInstrutor);
			cout<<"\t Cidade: "<<cidade[buscaT].nome<<"-"<<cidade[buscaT].uf;
			cout<<"\t Total de Participantes: "<<turma[i].total_participantes;
			cout<<"\t Quantidade Maxima de Participantes: "<<turma[i].quant_max_participantes;
	 		
		}
		else cout<<"\n***Turma nao encontrada***";

	}
    
}
void mostrar_turma (struct Turma turma[], int contTurma,struct Instrutor instrutor[],int contInstrutor,struct Curso curso[],int contCurso,struct Cidade cidade[],int contCidade){
	int t,buscaT=0;
	cout << "\n\n Digite o Codigo da Turma: ";
	cin>>t;
	t=t-1;
	if(busca_turma(turma,turma[t].codigo,contTurma)!= -1){
		buscaT=busca_turma(turma,turma[t].codigo_curso,contTurma);
		cout<<"\n Curso: "<<curso[buscaT].descricao;
		buscaT=busca_turma(turma,turma[t].codigo_instrutor,contTurma);
		cout<<"\t Instrutor: "<<instrutor[buscaT].nome;
		buscaT=busca_instrutor_turma(instrutor,instrutor[buscaT].codigo_cidade,contInstrutor);
		cout<<"\t Cidade: "<<cidade[buscaT].nome<<"-"<<cidade[buscaT].uf;
		cout<<"\t Total de Participantes: "<<turma[t].total_participantes;
	}
	else cout<<"\n***Turma nao encontrada***";
    
}

void mostrar_matricula (struct Matricula A[], int contA,struct Aluno aluno[],int contAluno,struct Turma turma[],int contTurma,struct Instrutor instrutor[],int contInstrutor,struct Curso curso[],int contCurso){
    int buscaR=0;
    int buscaC=0;
	cout << "\n\n Registros Matriculas" << endl;
    for (int i = 0; i < contA; i++){
       	cout << "\n  Codigo Matricula: " << A[i].codigo;
		if(busca_aluno(aluno,A[i].codigo_aluno,contAluno != -1)){
			buscaR = busca_aluno(aluno,A[i].codigo_aluno,contAluno);
			cout << "\t Aluno: " << aluno[buscaR].nome;
		}
		if(busca_turma(turma,A[i].codigo_turma,contTurma) != -1){
			buscaR=busca_turma(turma,A[i].codigo_turma,contTurma);
			buscaC=busca_curso(curso,turma[buscaR].codigo_curso,contCurso);
			cout<<"\t Curso: "<<curso[buscaC].descricao;
			buscaR=busca_turma(turma,turma[buscaR].codigo_instrutor,contInstrutor);
			cout<<"\t Instrutor: "<<instrutor[buscaR].nome;
        }
		cout << "\t	 Valor Total: " << A[i].valor_total;							
    }  
}

int main(){
	int menu_principal=0,menu_cidade=0,menu_curso=0,menu_instrutor=0,menu_aluno=0,menu_turma=0,menu_turma_consultar=0,menu_matricula=0,menu_sair=0;
	int invalido;
	
	Cidade cidadeV[z];
    int contCidade=0;
    
    Curso cursoV[z];
    int contCurso=0;
	
	struct Instrutor instrutores[z], arqT[z], instrutorS[z];
   	int contInstrutores=0, contT=0,contS=0;
   	
   	struct Aluno alunos[z],alunoT[z],alunoS[z];
   	int contAlunos=0,contAlunoT=0,contAlunoS=0;
   	int exclusao[z],contExclusao=0;
	
	struct Turma turmas[z],turmaT[z],turmaS[z];
	int contTurmas=0,contTurmaT=0,contTurmaS=0;
	
	struct Matricula matriculas[z], matriculaT[z],matriculaS[z];
	int contMatriculas=0,contMatriculaT=0,contMatriculaS=0;
	
	do{
		cout<<"  ________________________"<<endl;
		cout<<" |  MENU  PRINCIPAL 	  |" <<endl;
		cout<<" | 1 - Cidade		  |"<<endl;
		cout<<" | 2 - Curso		  |"<<endl;
		cout<<" | 3 - Instrutor	  |"<<endl;
		cout<<" | 4 - Aluno 		  |"<<endl;
		cout<<" | 5 - Turma 		  |"<<endl;
		cout<<" | 6 - Matricula	  |"<<endl;
		cout<<" | 7 - Encerrar	  	  |"<<endl;
		cout<<" |________________________|"<<endl;
		cout<<"\n Digite uma opcao: ";
		cin>>menu_principal;
		system("cls");
		
		switch(menu_principal){
			case 1:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  CIDADE	  |" <<endl;
					cout<<" | 1 - Cadastrar Cidades  |"<<endl;
					cout<<" | 2 - Consultar Cidades  |"<<endl;
					cout<<" | 3 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_cidade;
				
					switch(menu_cidade){
						case 1:{
							leitura_cidade(cidadeV,contCidade);
							system("cls");
							break;
						}
						case 2:{
							mostrar_cidade(cidadeV,contCidade);
							getch();
							system("cls");
							break;
						}
						case 3:{
							system("cls");
							break;
						}
					}
				}while(menu_cidade != 3);
				break;
			}
			case 2:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  CURSO	 	  |" <<endl;
					cout<<" | 1 - Cadastrar Cursos	  |"<<endl;
					cout<<" | 2 - Consultar Cursos	  |"<<endl;
					cout<<" | 3 - Voltar		  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_curso;
				
					switch(menu_curso){
						case 1:{
							leitura_curso(cursoV,contCurso);
							system("cls");
							break;
						}
						case 2:{
							mostrar_curso(cursoV,contCurso);
							getch();
							system("cls");
							break;
						}
						case 3:{
							system("cls");
							break;
						}
					} 
				}while(menu_curso != 3);
				break;
			}
			case 3:{
				do{
					cout<<"  ___________________________"<<endl;
					cout<<" |  MENU  INSTRUTOR	     |" <<endl;
					cout<<" | 1 - Cadastrar Instrutores |"<<endl;
					cout<<" | 2 - Consultar Instrutores |"<<endl;
					cout<<" | 3 - Voltar		     |"<<endl;
					cout<<" |___________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_instrutor;
					
					switch(menu_instrutor){
						case 1:{
							
							leitura_instrutor(arqT,contT,cidadeV,contCidade,instrutores,contInstrutores);
							inclusao_instrutor (instrutorS,contS, arqT, contT, instrutores , contInstrutores);				
				 			
							
							for (int i = 0; i < contInstrutores; i++) {
                        		instrutorS[i].codigo = instrutores[i].codigo;
                    			instrutorS[i].nome = instrutores[i].nome;
                        		instrutorS[i].endereco = instrutores[i].endereco;
                        		instrutorS[i].codigo_cidade = instrutores[i].codigo_cidade;
                			}

                			contS = contInstrutores;
                			
							system("cls");
							break;
						}
						case 2:{
							mostrar_instrutor(instrutores,contInstrutores);
							getch();
							system("cls");
							break;
						}
						case 3:{
							system("cls");
							break;
						}
					}
				}while(menu_instrutor !=3);	
				break;
			}
			case 4:{
				do{
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  ALUNO	     	  |" <<endl;
					cout<<" | 1 - Cadastrar Alunos   |"<<endl;
					cout<<" | 2 - Consultar Alunos   |"<<endl;
					cout<<" | 3 - Excluir Alunos 	  |"<<endl;
					cout<<" | 4 - Voltar	  	  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_aluno;
					
					switch(menu_aluno){
						case 1:{
							leitura_aluno(alunoT,contAlunoT,cidadeV,contCidade,alunos,contAlunos);
							inclusao_aluno(alunoS,contAlunoS,alunoT,contAlunoT,alunos,contAlunos);
							
							for (int i = 0; i < contAlunos; i++) {
                        		alunoS[i].codigo = alunos[i].codigo;
                    			alunoS[i].nome = alunos[i].nome;
                        		alunoS[i].endereco = alunos[i].endereco;
                        		alunoS[i].codigo_cidade = alunos[i].codigo_cidade;
                			}

                			contAlunoS = contAlunos;
                			
							system("cls");
					
							break;
					
						}
						
						case 2:{
							mostrar_alunos(alunos,contAlunos);
							getch();
							system("cls");
							break;
						}
					
						case 3:{
						
                			leitura_aluno_exclusao(exclusao, contExclusao);
                			exclusao_alunos(alunoS,contAlunoS,exclusao,contExclusao,alunos,contAlunos);
                			system("cls");
							
							cout<<"Codigo excluido com sucesso"<<endl;
                	
                	 		for (int i = 0; i < contAlunos; i++) {
                        		alunoS[i].codigo = alunos[i].codigo;
                    			alunoS[i].nome = alunos[i].nome;
                        		alunoS[i].endereco = alunos[i].endereco;
                        		alunoS[i].codigo_cidade = alunos[i].codigo_cidade;
                			}

                			contAlunoS = contAlunos;
							
							system("cls");
							break;
						}
						
						case 4:{
							system("cls");
							break;
						}
					}
				
				}while(menu_aluno != 4);
				break;
			}		
			
			
			case 5:{	
    			
				do{
					
					cout<<"  ________________________"<<endl;
					cout<<" |  MENU  TURMA	     	  |" <<endl;
					cout<<" | 1 - Cadastrar Turmas   |"<<endl;
					cout<<" | 2 - Consultar Turmas   |"<<endl;
					cout<<" | 3 - Voltar	  	  |"<<endl;
					cout<<" |________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_turma;
				
					switch(menu_turma){
						case 1:{
							leitura_turmas(turmaT,contTurmaT,cursoV,contCurso,cidadeV,contCidade,instrutores,contInstrutores);
							inclusao_turma(turmaS,contTurmaS,turmaT,contTurmaT,turmas,contTurmas);
							system("cls");
							
							
							for (int i = 0; i < contTurmas; i++) {
                        		turmaS[i].codigo = turmas[i].codigo;
                    			turmaS[i].codigo_curso = turmas[i].codigo_curso;
                        		turmaS[i].codigo_instrutor = turmas[i].codigo_instrutor;
                        		turmaS[i].total_participantes = turmas[i].total_participantes;
                        		turmaS[i].quant_max_participantes = turmas[i].quant_max_participantes;
                			}

                			contTurmaS = contTurmas;	
							
							system("cls");
							break;
						}
						case 2:{
							do{
								system("cls");
								cout<<"  ____________________________"<<endl;
								cout<<" |  MENU  CONSULTAR           |" <<endl;
								cout<<" | 1 - Consultar Turmas       |"<<endl;
								cout<<" | 2 - Consultar Turma Cheias |"<<endl;
								cout<<" | 3 - Voltar	  	      |"<<endl;
								cout<<" |____________________________|"<<endl;
								cout<<"\n Digite uma opcao: ";
								cin>>menu_turma_consultar;
							
								switch(menu_turma_consultar){
									case 1:{
										mostrar_turma(turmas,contTurmas,instrutores,contInstrutores,cursoV,contCurso,cidadeV,contCidade);
										getch();
										system("cls");
										break;
									}
									case 2:{
										mostrar_turma_max(turmas,contTurmas,instrutores,contInstrutores,cursoV,contCurso,cidadeV,contCidade);
										getch();
										system("cls");
										break;
									}
									case 3:{
										system("cls");
										break;
									}	
								
								}
							}while(menu_turma_consultar != 3);

							system("cls");
							break;
						}
						
						case 3:{
							system("cls");
							break;
						}
					}
							
				}while(menu_turma != 3);
				break;			
            }
            case 6:{
            	do{
				
					cout<<"  ____________________________"<<endl;
					cout<<" |  MENU  MATRICULA	      |" <<endl;
					cout<<" | 1 - Cadastrar Matriculas   |"<<endl;
					cout<<" | 2 - Consultar Matriculas   |"<<endl;
					cout<<" | 3 - Voltar	  	      |"<<endl;
					cout<<" |____________________________|"<<endl;
					cout<<"\n Digite uma opcao: ";
					cin>>menu_matricula;
            	
            		switch(menu_matricula){
            			case 1:{
            				leitura_matricula(matriculaT,contMatriculaT,alunos,contAlunos,turmas,contTurmas,instrutores,contInstrutores,cidadeV,contCidade,cursoV,contCurso);
							inclusao_matricula(matriculaS,contS,matriculaT,contT,matriculas,contMatriculas);
							system("cls");
							
							
							for (int i = 0; i < contMatriculas; i++) {
                        		matriculaS[i].codigo = matriculas[i].codigo;
                    			matriculaS[i].codigo_aluno = matriculas[i].codigo_aluno;
                        		matriculaS[i].codigo_turma = matriculas[i].codigo_turma;
                        		matriculaS[i].quantidade_aulas = matriculas[i].quantidade_aulas;
                        		matriculaS[i].valor_total = matriculas[i].valor_total;
                			}

                			contMatriculaS = contMatriculas;	
							
							system("cls");
							
							break;
						}
					
						case 2:{
							mostrar_matricula(matriculas,contMatriculas,alunos,contAlunos,turmas,contTurmas,instrutores,contInstrutores,cursoV,contCurso);
							getch();
							system("cls");
						break;
						}
					
						case 3:{
							system("cls");
						break;
						}
					}
				}while(menu_matricula!=3);
				break;
            }
			
            case 7:{
				cout<<"  _______________________"<<endl;
				cout<<" |  ENCERRAR O PROGRAMA  |" <<endl;
				cout<<" | 1 - Sim   		 |"<<endl;
				cout<<" | 2 - Nao	  	 |"<<endl;
				cout<<" |_______________________|"<<endl;
				cout<<"\n Digite uma opcao: ";
				cin>>menu_sair;
				
				switch(menu_sair){
					case 1:{
						system("cls");
						invalido=7;
						break;
					}
            		case 2:{
            			menu_principal=0;
						system("cls");
						break;
					}
				}
				break;
			}
			default:{
			cout<<" Opcao Invalida\n"<<endl;
        	getch();
        	system("cls");
        	invalido= 8;
			break;
			}
	
		}
	
	}while(menu_principal != 7);
}
