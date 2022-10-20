#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor

float converteSensor(int medida, float valor_minimo, float valor_maximo){
	//conversão do valor escolhido
	float zpercentage = 100*(medida-valor_minimo)/(valor_maximo-valor_minimo);
	//mostrando porcentagem
	cout << "Final answer is: " << zpercentage << "%\n";
	//retorna o valor em porcentagem
	return zpercentage;
}


// 2 - Faça uma função que simule a leitura de um sensor lendo o 
// valor do teclado ao final a função retorna este valor

int leituraSensor(int direcao){
	//declaro variavel
	int medida;
	//pede a medida da direção dependendo do valor
	if(direcao == 0){

	cout << "Leitura da medida da direita";
	cin >> medida;
	}
	if(direcao == 1){
	cout << "Leitura da medida da left";
	cin >> medida;
	}
	if(direcao == 2){
	cout << "Leitura da medida da up";
	cin >> medida;
	}
	if(direcao ==3){
	cout << "Leitura da medida da down";
	cin >> medida;
	}
	return medida;
}

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor
int armazenaVetor(int medida, int ultimoVetor, int *v, int vetorTamanho){
	//declaro variavel
	int *vetor =v;
	//Posiciona o numero no ultimo colocado do vetor
	vetor[ultimoVetor] = medida;
	//retorna a proxima colocação do vetor
	return ultimoVetor+1;
}

// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.
char* direcaoMenorCaminho(int *vector, int *maxValue){
	//declaro variavel
	char* direcao[] = {"Direita", "Esquerda", "Frente", "Tras"};
	//declaro variavel
	int index;
	//for loop para averiguar o valor em cada direção
	for (int i = 0; i < 4; i++) {
		//Escolhe o maior valor considerando as posições
		if(vector[i] > *maxValue){
			*maxValue = vector[i];
			index = i;
		}
	}
	//retorna a direção
	return direcao[index];
}
// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso

int leComando() {
	//declaro variavel
	int answer;
	//pergunta para o usuario se quer continuar
	cout << "Quer continuar ou mapeamento, coloque 1 se sim e 0 se nao";
	cin >> answer;
	//retorna a resposta do usuario
	return answer;
}

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
int dirige(int *v,int maxv){
	//declaro variavel
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;
	//while loop para o aplicativa caso resposta for sim
	while(dirigindo){
		//funções são chamadas para cada direção
		for(int i=0; i<4; i++){		

			int medida = leituraSensor(i);/// .. Chame a função de de leitura 
			medida = converteSensor(medida,0,830);
			posAtualVetor = armazenaVetor(medida, posAtualVetor, vetorMov, maxVetor);// Chame a função para armazenar a medida no vetor

		}
		//pergunta o usuario se quer continuar
		dirigindo = leComando();	

	}
	//retorna 
	return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = direcaoMenorCaminho(&(vetorMov[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i%\n",direcao,maiorDir);
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}