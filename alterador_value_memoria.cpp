#include <iostream>
#include <windows.h>

int main(int argc, char** argv) {
	
	int newValue = 333;
	
	HWND hwnd = FindWindow(0, "C:\\Users\\vilim\\OneDrive\\Documentos\\c\\memoria2.exe");      //Identificar o id/handle  do programa no windows, Localiza a janela pelo título
	//Verificar se conseguiu encontrar
	if(hwnd == 0){
		std::cout << "Erro ao acessar programa" << std::endl;
		return 1;
	}
	std::cout << "ACESSO OK." << std::endl;
	
	
	DWORD pId;
	GetWindowThreadProcessId(hwnd, &pId);	    //Obter o identificador da thread que criou uma janela - (O primeiro parâmetro é o handle da janela (HWND), O segundo parâmetro é um ponteiro para uma variável que receberá o ID do processo)
	
	HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pId);			//Obtem o identificador para alterar o conteudo do processo
	//Se nao conseguiu achar o id para alterar a memoria
	if (!hProc){
		std::cout << "Erro ao abrir o processo!" << std::endl;
		return 1;
	}
	BOOL rc = WriteProcessMemory(hProc, (LPVOID)0x1FBBDD18D38, &newValue, (SIZE_T)sizeof(newValue), NULL);		//Se conseguiu, escreva na memoria( Processo que solicitou a gravacao, endereço de momoria, novo valor, tamanho do tipo, retorna a quantidade de bytes gravados )
	if (rc){
		std::cout << "Memoria Alterada!" << std::endl;
	}
	else{
		std::cout << "ERRO AO ALTERAR!" << std::endl;
	}
	
	CloseHandle(hProc);				//Fechar o handle do processo
	
	
	return 0;
}
