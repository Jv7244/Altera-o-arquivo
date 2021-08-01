#include<iostream>
#include<fstream>
#include<string.h>
#include<new>

using namespace std;

struct dadosUsuario{
     char nomeCompleto[255];
     int idade;
     char sexo;
};

//função de criação de arquivo
string criandoAquivo(string nome,int idade, char sexo);

//função para apagar o conteudo do arquivo
void apagaConteudo();

int main(){

    //aqui eu criei uma struct com nome dados
    dadosUsuario *dados = new dadosUsuario;

    cout << "\n Digite seu nome completo : ";
    gets(dados->nomeCompleto);

    cout << "\n Digite sua idade : ";
    cin >> dados->idade;

    cout << "\n Digite seu sexo : ";
    cin >> dados->sexo;

    apagaConteudo();
    
    //Aqui eu mando os dados da struct como parametro para minha função arquivo
    criandoAquivo(dados->nomeCompleto,dados->idade,dados->sexo);

    return 0;
}

//função de criação de arquivo
string criandoAquivo(string nome,int idade, char sexo){

    //aqui eu criei o objeto arquivo
    ofstream arquivo;

    //aqui eu criei o arquivo com nome texto e extensão txt
    arquivo.open("texto.txt",std::ios_base::app);

    arquivo << "";
    arquivo << "Nome completo : " << nome;
    arquivo << "\nIdade : " << idade << " anos";
    arquivo << "\n";
    if(sexo == 'M' || sexo == 'm'){
        arquivo << "Sexo : " << sexo << " Masculino ";
    }
    else{
        arquivo << "Sexo : " << sexo << " Feminino ";
    }

    arquivo.close();

}

//função para apagar o conteudo do arquivo
void apagaConteudo(){
    ofstream arquivo1;

    arquivo1.open("texto.txt");

    arquivo1 << "";

    arquivo1.close();
}