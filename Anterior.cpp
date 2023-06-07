# include <bits/stdc++.h>

using namespace std;

int n;
bitset<10005> di, ds;
vector<vector<int>> tabu;

void Limpiar_Tabu()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) tabu[i][j] = 0;
    }
}

struct Solucion
{
    vector<int> camino;
    pair<int, int> cambios;
    int colisiones;

    void Inicializar()
    {
        camino.resize(n);
        for(int i=0;i<n;i++) camino[i] = i;
        cambios = {0,0};
        colisiones = 0;
    }

    void Colisiones()
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

    void Aleatoria()
    {
        for(int i=0;i<n;i++) camino[i] = i;
        for(int i=0;i<n;i++) swap(camino[i], camino[rand() % n]);
    }

    void Imprimir()
    {
        cout << colisiones << ": "; 
        for(auto &e:camino) cout << e+1 << " ";
        cout << endl;
    }

    void Imprimir_Matriz()
    {
        vector<vector<int>> matriz(n, vector<int>(n, 0));
        for(int i=0;i<n;i++)
        {
            matriz[camino[i]][i] = 1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cout << matriz[i][j] << " ";
            cout << endl;
        }
    }
};

vector<Solucion> Vecinos(Solucion &sol)
{
    vector<Solucion> s;
    for(int i=0;i<n;i++)
    {
        int x = rand() % n;
        swap(sol.camino[i], sol.camino[x]);
        sol.Colisiones();
        s.push_back(sol);
        swap(sol.camino[i], sol.camino[x]);
    }
    sol.Colisiones();
    
    return s;
}

bool Comparar_Tabu(vector<Solucion> &Tabu, Solucion &s)
{
    for(auto &e:Tabu)
    {
        bool val = true;
        for(int i=0;i<n;i++)
        {
            if(s.camino[i] != e.camino[i])
            {
                val = false;
                break;
            }
        }

        if(val) return false;
    }

    return true;
}

int main()
{
    unsigned t0 = clock();
    freopen("resultado.txt", "w", stdout);
    cin>>n;
    if(n > 5000)
    {
        cout << "No se permiten tableros mÃ¡s grandes de 5000" << endl;
        return 0;
    }

    srand(time(NULL));

    Solucion actual;
    Solucion mejor;
    Solucion best;

    actual.Inicializar();
    mejor.Inicializar();
    best.Inicializar();
    best.colisiones = n;

    int tabu = 50;
    int iteraciones = 3000;
    int ite = 500;
    int tt;

    cout << "Sea el tablero de ajedrez de tamaÃ±o " << n << "x" << n << endl;
    cout << "Se hicieron " << ite << " iteraciones con " << iteraciones << " modificaciones cada una" << endl;
    cout << endl;

    for(int z=1;z<=ite;z++)
    {
        tt = iteraciones;
        actual.Aleatoria();
        actual.Colisiones();
        vector<Solucion> vecinos;
        vector<Solucion> Tabu(tabu);

        for(int i=0;i<tabu;i++) Tabu[i] = actual;
        
        int cont = 0;
        vecinos = Vecinos(actual);
        while(tt--)
        {
            actual = vecinos[0];
            for(auto &sol:vecinos)
            {
                if(sol.colisiones < actual.colisiones && Comparar_Tabu(vecinos, actual)) actual = sol;
            }

            Tabu[cont] = actual;
            mejor = actual;
            cont = (cont+1) % tabu;
        }

        cout << "Mejor solucion iteraciÃ³n " << z << " -> ";
        mejor.Imprimir();

        if(mejor.colisiones < best.colisiones) best = mejor;
    }

    cout << endl << "SoluciÃ³n final: " << endl;
    best.Imprimir();
    cout << endl << "En forma matricial queda como: " << endl;;
    best.Imprimir_Matriz();

    cout << endl << endl;
    unsigned t1 = clock();
    double time = ( double (t1-t0)/CLOCKS_PER_SEC); cout << "Execution Time: " << time << endl;

    return 0;
}