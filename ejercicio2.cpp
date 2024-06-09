#include <iostream>
#include <string>

using namespace std;

struct TablaHash {
	char abecedario[26];
	TablaHash() {
		for (int i = 0; i < 26; ++i) {
			abecedario[i] = '\0';
		}
	}
};

int obtenerPosicion(char letra) {
	return letra - 'a';
}

TablaHash crearTablaHash(const string& clave) {
	TablaHash tabla;
	int index = 0;
	for (char c : clave) {
		if (c != ' ' && tabla.abecedario[obtenerPosicion(c)] == '\0') {
			tabla.abecedario[obtenerPosicion(c)] = 'a' + index++;
		}
	}
	return tabla;
}

string decodeMessage(const TablaHash& tabla, const string& mensaje) {
	string mensajeDecodificado;
	for (char c : mensaje) {
		if (c == ' ') {
			mensajeDecodificado += ' ';
		} else {
			mensajeDecodificado += tabla.abecedario[obtenerPosicion(c)];
		}
	}
	return mensajeDecodificado;
}

int main() {
	string clave = "the quick brown fox jumps over the lazy dog";
	string mensaje = "vkbs bs t suepuv";
	TablaHash tabla = crearTablaHash(clave);
	string mensajeDecodificado = decodeMessage(tabla, mensaje);

	cout << mensajeDecodificado << endl;

	/*string clave = "abcdefghijklmnopqrstuvwxyz";
	string mensaje = "i love lourdes";
	TablaHash tabla = crearTablaHash(clave);
	string mensajeDecodificado = decodeMessage(tabla, mensaje);

	cout << mensajeDecodificado << endl;*/

	return 0;
}