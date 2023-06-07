# include <bits/stdc++.h>

using namespace std;

int c1 = 1; // Peso asignado a las colisiones de las resinas
int c2 = 1; // Peso asignado a las reinas a distancia de caballo

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
        vector<vector<char>> matriz(n, vector<char>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) matriz[i][j] = '.';
        }

        for(int i=0;i<n;i++) matriz[camino[i]-1][i] = '0';

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
        for(int j=i;j<n;j++) if(tabu[i][j] != 0) tabu[i][j]--;
    }
}

void Imprimir()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cout << tabu[i][j] << " ";
        cout << endl;
    }
    cout << endl << endl;
}

int main()
{
    freopen("resultado.txt", "w", stdout);
    cin>>n;
    tabu.resize(n, vector<int>(n));

    srand(time(NULL));

    int num_sol_alea = 1; // Cantidad de veces que se empezará con una solución aleatorio nueva
    int iteraciones = 100; // Cantidad de iteraciones por solución aleatorio nueva
    int t = 25; // Número de iteraciones que se vuelve tabú un movimiento
    int ite;

    Solucion permutacion, superior, actual, mejor;
    mejor.Inicializar();
    mejor.Aleatorio();
    mejor.Calcular();
    mejor.Imprimir_Matriz();

    int a, b, p;
    bool val;

    while(num_sol_alea--)
    {
        superior.Inicializar();
        superior.Aleatorio();
        superior.Calcular();
        actual = superior;
        Limpiar_Tabu();

        ite = iteraciones;
        while(ite--)
        {
            Imprimir();
            Bajar_Tabu();
            superior.criterio = INT_MAX;
            for(int i=0;i<n;i++)
            {
                p = rand() % n;
                if(p == i) continue;

                a = min(i, p);
                b = max(i, p);

                if(tabu[a][b] != 0) continue;

                permutacion = actual;
                swap(permutacion.camino[a], permutacion.camino[b]);
                permutacion.cambio = {a,b};
                permutacion.Calcular();
                permutacion.criterio += tabu[b][a];

                if(permutacion.criterio < superior.criterio) superior = permutacion;
                if(superior.criterio < mejor.criterio) mejor = superior;
            }

            if(superior.criterio != INT_MAX)
            {
                tabu[superior.cambio.second][superior.cambio.first]++;
                tabu[superior.cambio.first][superior.cambio.second] = t+1; 
                actual = superior;
            }
        }

        cout << mejor.criterio << endl;
    }

    mejor.Imprimir_Matriz();

    return 0;
}