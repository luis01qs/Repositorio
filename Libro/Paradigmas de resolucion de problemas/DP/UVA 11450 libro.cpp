# include <bits/stdc++.h>
using namespace std;

int i, j, TC, ans, M, C, price[30][30];
int memo[210][30];

int shop(int money, int g)
{
    if(money < 0) return -1000000000;
    if(g == C) return M-money;
    if(memo[money][g] != -1) return memo[money][g];
    int ans = -1;
    for(int model = 1; model <= price[g][0]; model++)
    {
        ans = max(ans, shop(money-price[g][model], g+1));
    }

    return memo[money][g] = ans;
}

int main()
{
    scanf("%d", &TC);
    while(TC--)
    {
        scanf("%d %d", &M, &C);
        for(i = 0;i<C;i++)
        {
            scanf("%d", &price[i][0]);
            for(j = 1; j<=price[i][0];j++)
            {
                scanf("%d", &price[i][j]);
            }
        }

        memset(memo, -1, sizeof memo);
        ans = shop(M, 0);

        if(ans < 0) printf("no solution\n");
        else printf("%d\n", ans);
    }
}