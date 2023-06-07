# include <bits/stdc++.h>

using namespace std;

int c1 = 1; // Peso asignado a las colisiones de las resinas
int c2 = 3; // Peso asignado a las reinas a distancia de caballo

int n;
bitset<10005> di, ds;
vector<vector<int>> tabu;

struct Solucion
{
    vector<int> camino;
    pair<int, int> cambio;
    int colisiones;
    int caballo;
    int criterio;

    void Inicializar()
    {
        camino.resize(n);
        for(int i=0;i<n;i++) camino[i] = i+1;
        cambio = {0,0};
        colisiones = 0;
        caballo = 0;
        criterio = 0;
    }

    void Imprimir_Matriz()
    {
        cout << criterio << ":" << endl << "Colisiones: " << colisiones << endl << "Caballo: " << caballo <<  endl;
        vector<vector<int>> matriz(n, vector<int>(n, 0));
        for(int i=0;i<n;i++)
        {
            matriz[camino[i]-1][i] = 1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cout << matriz[i][j] << " ";
            cout << endl;
        }
    }

    void Aleatorio()
    {
        for(int i=0;i<n;i++)
        {
            swap(camino[i], camino[rand() % n]);
        }
    }

    void Calcular_Colisiones() // Determina cuantas colisiones de reinas están sucediendo
    {
        di.reset();
        ds.reset();

        colisiones = 0;
        for(int i=0;i<n;i++)
        {
            int x = i;
            int y = camino[i];

            if(ds[n-x+n-y]) colisiones++;
            if(di[y+n-x]) colisiones++;

            ds[n-x+n-y] = di[y+n-x] = 1;
        }
    }

    void Calcular_Caballos() // Determina cuantas reinas están a distancia de caballo 
    {
        caballo = 0;
        for(int i=0;i<n;i++)
        {
            if(i > 0 && abs(camino[i] - camino[i-1]) == 2) caballo++;
            if(i > 1 && abs(camino[i] - camino[i-2]) == 1) caballo++;  
        }
    }

    void Calcular_Criterio()
    {
        criterio = colisiones*c1 - caballo*c2;
    }

    void Calcular()
    {
        Calcular_Colisiones();
        Calcular_Caballos();
        Calcular_Criterio();
    }
};

void Limpiar_Tabu()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) tabu[i][j] = 0;
    }
}

void Bajar_Tabu()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) if(tabu[i][j] != 0) tabu[i][j]--;
    }
}

int main()
{
    freopen("resultado.txt", "w", stdout);
    //cin>>n;
    n = 10;
    Solucion s;
    s.Inicializar();
    s.Aleatorio();
    s.Calcular();
    s.Imprimir_Matriz();

    return 0;
}