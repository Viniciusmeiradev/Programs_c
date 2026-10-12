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
    private:
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
                }else{
                    for (auto& c : candidatos){
                        if(c.numero == num){
                            break;
                        }
                    }
                }
            }
            arquivo.close();
        }
        void salvarVoto(int numero, std::string tipo){
            std::ofstream arquivo(arquivoBD, std::ios::app);
            if(arquivo.is_open()){
                arquivo << numero << " " << tipo << "\n";
                arquivo.close();
            }
        }

    public:
        UrnaEletronica(){
            votosBrancosDeputado_federal = 0;  //4
            votosBrancosDeputado_estadual = 0; //6
            votosBrancosSenador = 0;  //3
            votosBrancosGovernador = 0; //2
            votosBrancosPresidente = 0; //2

            votosNulosDeputado_federal = 0;
            votosNulosDeputado_estadual = 0;
            votosNulosSenador = 0;
            votosNulosGovernador = 0;
            votosNulosPresidente = 0;

            candidatos.push_back({11, "Joel Silva", "Partido Republicano", "Governador", 0});
            candidatos.push_back({4578, "Janaina Ribeiro", "Partido Democrata", "Deputado_federal", 0});
            candidatos.push_back({66, "Anderson Nogueira", "Partido Republicano", "Governador", 0});
            candidatos.push_back({114754, "Yasmim Jandaira", "Partido Republicano", "Deputado_estadual", 0});
            candidatos.push_back({7974, "Pedro Leopoldo", "Partido Republicano", "Deputado_federal", 0});
            candidatos.push_back({556445, "Carlos Magno", "Partido Democrata", "Deputado_estadual", 0});
            candidatos.push_back({17, "Stephane Ralap", "Partido Republicano", "Presidente", 0});
            candidatos.push_back({19, "Luis Gonzages", "Partido Democrata", "Presidente", 0});
            candidatos.push_back({115, "Jamuel Rabelo", "Partido Democrata", "Senador", 0});
            candidatos.push_back({1199, "Leticia Leite", "Partido Democrata", "Deputado_federal", 0});

            carregarBancoDados();
        }

        Candidato* buscarCandidato(int numero, std::string cargo){
            for(auto& c: candidatos){
                if(c.numero == numero && c.cargo == cargo){
                    return &c;
                }
            }
            ruturn nullptr;
        }

        void registrarVoto


        
