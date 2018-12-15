//#include <Game/Game.hpp>
#include <iostream>
#include <fstream>
#include <string>
/*Game::Game(GameManager){

}

void Game::loadMap(const FilePath &path, int nbFloor){

	for(int i = 0; i<nbFloor ; i++){
		loadFloor(path + std::to_string(i) + ".txt");
	}
}*/

void loadFloor(/*const FilePath &file*/){
	std::ifstream fileLevel("/mnt/c/Users/cecil/Documents/IMAC2/ProjetSyntheseImage/Temple_Run/Level/test1.ppm");  //Ouverture d'un fichier en lecture

	int w, h, i, j, r, g, b, max;
	
	//If we can read the file
	if(fileLevel){

		//First line with p3
		std::string line;
		getline(fileLevel, line);

		//Second line with width and height
		fileLevel >> w;
		fileLevel >> h;

		std::cout << "w : " << w << std::endl;
		std::cout << "h : " << h << std::endl;

		//Third line with maximal color value
		fileLevel >> max;

		for(i=0 ; i<h; i++){
			for(j=0 ; j<w; j++){
				fileLevel >> r;
				fileLevel >> g;
				fileLevel >> b;

				if(r==max && g==0 && b==0){
					std::cout << "Red" << std::endl;					
					std::cout << "Coordonnées : " << i << "," << j << std::endl;					
				}

				if(r==0 && g==max && b==0){
					std::cout << "Green" << std::endl;					
				}

				if(r==0 && g==0 && b==max){
					std::cout << "Blue" << std::endl;					
				}
			}
		}

	}
	//If we can't read it
	else{
	    std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
	}
}

int main(){
	loadFloor();
}