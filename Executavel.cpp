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
void leitura_cidade(struct Cidade cidade[],int &cont){
    int i = 0;    
	
	for (int saida = 1; i < z && saida != 0; i++){
		cout<<"\n Registro [ "<<i + 1<<" ]"<<endl;
		cout<<" --------------------------"<<endl;
		cout << " Codigo da Cidade: ";
        cin >> cidade[i].codigo;
        cin.ignore();
        if (cidade[i].codigo > 0){
            cout<<" --------------------------"<<endl;
			cout << " Nome da Cidade: ";
            getline(cin,cidade[i].nome);
           	cout<<" --------------------------"<<endl;
		    cout << " UF da Cidade: ";
            getline(cin,cidade[i].uf);
            cout<<" --------------------------"<<endl;
        }
        else saida = 0;
    }
    cont = i-1;
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
        	cout<<" --------------------------"<<endl;
			cout<<" Descricao do Curso: ";
        	getline(cin,curso[i].descricao);
        	cout<<" --------------------------"<<endl;
			cout<<" Valor por Aula: ";
        	cin>>curso[i].valor_por_aula;
        	cin.ignore();
        	cout<<" --------------------------"<<endl;

		}
		else saida = 0;

    	
    }
    cont = i-1;
}

int busca_cidade (struct Cidade v[], int cod,int cont){
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

bool busca_instrutor (struct Instrutor v[], int cod,int cont){
    
	int i = 0, f = cont -1 ;
	
	if(f == -1){
		return true;
	}
    
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
    else return true ;
}



bool busca_serial_instrutor (struct Instrutor inst[], int cod,int cont){
    int i = 0;
    for (; i < cont && cod > inst[i].codigo; i++);
    if (cod == inst[i].codigo){
       return true;
       
    }
    else
        return false;
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
				if(busca_instrutor(inst,inst[i].codigo,i) and busca_instrutor(instrutor,instrutor[i].codigo,cont)){
					cout<<"salve";
					cout<<" --------------------------"<<endl;
					cout<<" Nome do Instutor: ";
        			getline(cin,inst[i].nome);
        			cout<<" --------------------------"<<endl;
					cout<<" Endereco do instrutor: ";
					getline(cin,inst[i].endereco);
            		for(;x != -1;){
						cout<<" --------------------------"<<endl;
						cout<<" Codigo da cidade: ";
						cin>>inst[i].codigo_cidade;
                		cin.ignore();
						if(busca_cidade(vetorCidade,inst[i].codigo_cidade,contCidade) != -1){
                    		buscaR=busca_cidade(vetorCidade,inst[i].codigo_cidade,contCidade);
                    		cout<<" --------------------------"<<endl;
							cout<<" Cidade: "<<vetorCidade[buscaR].nome<<"-"<<vetorCidade[buscaR].uf<<endl;
							cout<<" --------------------------"<<endl;
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
			}else{
				
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

/*void leitura_instrutor(struct Instrutor NovoInst[], int &contInstrutorT, struct Instrutor InstCadastrados[], int contInstCadastrados, struct Cidade vetorCidade[], int qtdRegistrosCidade){
	
	int i=0, contPassou=0;
	
	cout<<"\nLEITURA INSTRUTOR\n";
	
	for(int saida = 1; i < z && saida != 0; i++){
		  for(int x = 1; x != -1;){
			cout<<"\nCodigo Instrutor: ";
			cin>>NovoInst[i].codigo;
			cin.ignore();
				if(NovoInst[i].codigo > 0){
					
					if( busca_instrutor(NovoInst, NovoInst[i].codigo, i) ==true && busca_instrutor(InstCadastrados, NovoInst[i].codigo, contInstCadastrados) == true){
						cout<<"Nome: ";
						getline(cin, NovoInst[i].nome);
						cout<<"Endereco: ";
						getline(cin,NovoInst[i].endereco);
			
						for(; x != -1;){
								cout<<"Codigo Cidade: ";
								cin>>NovoInst[i].codigo_cidade;
	
								int resultado = busca_cidade(vetorCidade, NovoInst[i].codigo_cidade, qtdRegistrosCidade);
				
							if(resultado != -1){
								cout<<"Cidade: " << vetorCidade[resultado].nome;
								cout<<"\tUF: " << vetorCidade[resultado].uf << endl;
								x = -1;
						
							}else cout<<"\nCodigo de cidade invalido, digite novamente\n";
						}
							
				}else {
				cout<<"\nEsse codigo ja existe. Digite outro codigo\n"; contPassou++;
				}
			}else saida = 0;  
					x = -1;
		}

	}				
	if(i == z){
            contInstrutorT = i;
            
        } else contInstrutorT = i - 1;
        
        contInstrutorT = contInstrutorT - contPassou;
        
        cout<< "CONT PASSOU: " << contPassou;
        
	 cout<<"\nCONT VALE: " << contInstrutorT;
}
*/

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
					if(busca_cidade(vetorCidade,aluno[i].codigo_cidade,contCidade) != -1){
                    	buscaR=busca_cidade(vetorCidade,aluno[i].codigo_cidade,contCidade);
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

bool Busca_aluno_inclusao (struct Aluno v[], int cod,int cont){
    
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

/*void Leitura_aluno_inclusao(struct Aluno aluno[],struct Cidade vetorCidade[],struct Aluno alunoV[],int contV, int &cont,int contCidade){
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
			if(Busca_aluno_inclusao(alunoV,aluno[i].codigo,contV) == true){
				if(Busca_aluno_inclusao(aluno,aluno[i].codigo,i) == true){
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
			} else cout<<"\n ***Codigo ja existente***"<<endl;
		
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
*/

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

void mostrar_instrutor (struct Instrutor A[], int contA){
    cout << "\n\n Lista dos Registros no Arquivo Atualizado" << endl;
    for (int i = 0; i < contA; i++){
        cout << "\nCodigo: " << A[i].codigo;
        cout << "\tNome: " << A[i].nome;
        cout << "\tEndereco: " << A[i].endereco;
        cout << "\tCidade: " << A[i].codigo_cidade;
    }  
}

void mostrar_alunos (struct Aluno A[], int contA){
    cout << "\n\n Lista dos Registros no Arquivo Atualizado" << endl;
    for (int i = 0; i < contA; i++){
        cout << "\nCodigo: " << A[i].codigo;
        cout << "\tNome: " << A[i].nome;
        cout << "\tEndereco: " << A[i].endereco;
        cout << "\tCidade: " << A[i].codigo_cidade;
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

int main(){
	int menu_principal=0,menu_cidade=0,menu_curso=0,menu_instrutor=0;
	int invalido;
	
	Cidade cidadeV[z];
    int contCidade=0;
    
    Curso cursoV[z];
    int contCurso=0;
	
	struct Instrutor instrutores[z], arqT[z], instrutorS[z];
   	int contInstrutores=0, contT=0,contS=0;
	
	
	
	do{
		cout<<"  ________________________"<<endl;
		cout<<" |  MENU  PRINCIPAL 	  |" <<endl;
		cout<<" | 1 - Cidade		  |"<<endl;
		cout<<" | 2 - Curso		  |"<<endl;
		cout<<" | 3 - Instrutor	  |"<<endl;
		cout<<" | 4 - ALUNO 		  |"<<endl;
		cout<<" |________________________|"<<endl;
		cout<<"\n Digite uma opcao: ";
		cin>>menu_principal;
		system("cls");
		
		invalido=5;

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
							
							//leitura_instrutor(arqT,contT,instrutores,contInstrutores,cidadeV,contCidade);
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
			
			/*case 4:{
				Leitura_aluno(Valuno,cidadeV,contAluno,contCidade);
				break;
			}
			/*
			/*case 5:{	
    			Leitura_instrutor_inclusao (arqT,cidadeV,instrutorV,contInstrutor,contT,contCidade);
    			inclusao_instrutor (instrutorV,contInstrutor, arqT, contT, arqA, contA);   
				mostrar_instrutor(arqA,contA);
				break;
            }
            
			
			case 6:{	
    			Leitura_aluno_inclusao (arqT_aluno,cidadeV,Valuno,contAluno,contT_aluno,contCidade);
    			inclusao_Alunos (Valuno,contAluno, arqT_aluno, contT_aluno, arqA_aluno, contA_aluno);
   				mostrar_alunos(arqA_aluno,contA_aluno);
				break;
            }
            
            case 7:{	
    			 int codLeitura=0;
				
				for (; contT_aluno_ex < 20 && codLeitura > 0; contT_aluno_ex++){
        			cout << "\nInforme o Codigo do Registro a ser Excluido (finalize com 0): ";
        			cin >> codLeitura;
        			if(codLeitura != 0){
            		arqT_aluno_ex[contT_aluno_ex] = codLeitura;
        			}
    			} 
    			exclusao_alunos (Valuno,contAluno,arqT_aluno_ex,contT_aluno_ex,arqA_aluno_ex,contA_aluno_ex);
   				mostrar_alunos(arqA_aluno_ex,contA_aluno_ex);
				break;
            }
            */
			
			default:{
				cout<<"Opção inválida\n"<<endl;
        		invalido= 5;
				break;
			}
		}
	
	}while(invalido);

}
