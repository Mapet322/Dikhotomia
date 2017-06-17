#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

class objeto{
protected:
    int posx;
    int posy;
    SDL_Surface *imagen;
    int salud;
    int estado;
public:
    int get_posx() {return posx;}
    int get_posy() {return posy;}
    int get_salud() {return salud;}
    int get_estado() {return estado;}
    void set_posx(int aux) {posx = aux;}
    void set_posy(int aux) {posy = aux;}
    void set_salud(int aux) {salud = aux;}
    void set_estado(int aux) {estado = aux;}
};

class jugador:objeto{
protected:
    int puntaje;
    char nombre[20];
public:
    int get_puntaje() {return puntaje;}
    char *get_nombre() {return nombre;}
    void set_puntaje(int aux) {puntaje = aux;}
    void set_nombre(char aux[20]) {strcpy(nombre, aux);}
};

class enemigo:objeto{
public:


};

#endif // CLASES_H_INCLUDED
