#include <string>
#include <fstream>
#include <iostream>

struct Candidato{
    int numero;
    std::string nome;
    std::string partido;
    std::string cargo;
    int votos;
};

class UrnaEletronica{
    std::vector<Candidato> candidatos;
    int votosBrancosDeputado_federal;
    int votosBrancosDeputado_estadual;
    int votosBrancosSenador;
    int votosBrancosGovernador;
    int votosBrancosPresidente;

    int votosNulosDeputado_federal;
    int votosNulosDeputado_estadual;
    int votosNulosSenador;
    int votosNulosGovernador;
    int votosNulosPresidente;

    const std::string arquivoBD = "votos_bd.txt";

    void carregarBancoDados{
        std::ifstream arquivo(arquivoBD);
        if (!arquivo.is_open()) return;
        
        int num;
        std::string tipo;
        while (arquivo >> num >> tipo){
            if (num == -1){
                if (tipo == "NuloDeputado_federal") votosNulosDeputado_federal++;
                else if (tipo == "BrancoDeputado_federal") votosBrancosDeputado_federal++;

                else if(tipo == "NuloDeputado_estadual") votosNulosDeputado_estadual++;
                else if(tipo == "BrancoDeputado_estadual")votosBrancosDeputado_estadual++;

                else if(tipo == "NuloSenador") votosNulosSenador++;
                else if(tipo == "BrancoSenador")votosBrancosSenador++;

                else if(tipo == "NuloGovernador") votosNulosGovernador++;
                else if(tipo == "BrancoGovernador") votosNulosGovernador++;

                else if(tipo == "NuloPresidente") votosNulosPresidente++;
                else if(tipo == "BrancoPresidente") votosBrancosPresidente++;
            }
        }

    }

}