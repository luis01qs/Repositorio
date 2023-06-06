#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Function to check if two queens threaten each other
bool isConflict(int row1, int col1, int row2, int col2) {
    return (row1 == row2) || (col1 == col2) || (abs(row1 - row2) == abs(col1 - col2));
}

// Function to calculate the number of conflicts for the current solution
int calculateConflicts(const vector<int>& queens) {
    int conflicts = 0;
    int n = queens.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isConflict(i, queens[i], j, queens[j]))
                conflicts++;
        }
    }

    return conflicts;
}

// Function to calculate the maximum distance between conflicting queens
int calculateMaxDistance(const vector<int>& queens) {
    int maxDistance = 0;
    int n = queens.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isConflict(i, queens[i], j, queens[j])) {
                int distance = max(abs(queens[i] - queens[j]), abs(i - j));
                if (distance > maxDistance)
                    maxDistance = distance;
            }
        }
    }

    return maxDistance;
}

// Function to generate a random permutation
vector<int> generateRandomPermutation(int n) {
    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = i;
    }
    random_shuffle(permutation.begin(), permutation.end());
    return permutation;
}

// Function to generate a random solution (permutation)
vector<int> generateRandomSolution(int n) {
    vector<int> queens = generateRandomPermutation(n);
    return queens;
}

// Function to generate a neighboring solution
vector<int> generateNeighboringSolution(const vector<int>& currentSolution) {
    int n = currentSolution.size();
    vector<int> newSolution = currentSolution;

    // Randomly select two positions and swap the queens
    int pos1 = rand() % n;
    int pos2 = rand() % n;
    swap(newSolution[pos1], newSolution[pos2]);

    return newSolution;
}

// Function to calculate the multiobjective value
double calculateMultiobjectiveValue(const vector<int>& queens, double w1, double w2) {
    int conflicts = calculateConflicts(queens);
    int maxDistance = calculateMaxDistance(queens);

    return w1 * conflicts - w2 * maxDistance;
}

// Tabu Search algorithm for solving the n-queens problem using a multiobjective approach
void solveNQueensTabuSearch(int n, int maxIterations, int tabuSize, double w1, double w2) {
    srand(time(0));

    vector<int> currentSolution = generateRandomSolution(n);
    vector<int> bestSolution = currentSolution;
    double bestMultiobjectiveValue = calculateMultiobjectiveValue(currentSolution, w1, w2);

    vector<vector<int>> tabuList(tabuSize, vector<int>(n, -1));
    unordered_set<int> tabuSet;

    int currentIteration = 0;

    while (currentIteration < maxIterations) {
        vector<int> bestNeighbor;
        double bestNeighborMultiobjectiveValue = numeric_limits<double>::max();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (currentSolution[i] != j) {
                    vector<int> neighbor = currentSolution;
                    neighbor[i] = j;

                    double neighborMultiobjectiveValue = calculateMultiobjectiveValue(neighbor, w1, w2);

                    if (neighborMultiobjectiveValue < bestNeighborMultiobjectiveValue &&
                        tabuSet.find(neighbor[i]) == tabuSet.end()) {
                        bestNeighbor = neighbor;
                        bestNeighborMultiobjectiveValue = neighborMultiobjectiveValue;
                    }
                }
            }
        }

        currentSolution = bestNeighbor;
        double currentMultiobjectiveValue = calculateMultiobjectiveValue(currentSolution, w1, w2);

        // Update the best solution if the current solution has a better multiobjective value
        if (currentMultiobjectiveValue < bestMultiobjectiveValue) {
            bestSolution = currentSolution;
            bestMultiobjectiveValue = currentMultiobjectiveValue;
        }

        // Add the current move to the tabu list
        tabuSet.insert(currentSolution[0]);
        tabuList[currentIteration % tabuSize] = currentSolution;

        currentIteration++;
    }

    // Print the best solution
    cout << "Best solution: ";
    for (int i = 0; i < bestSolution.size(); i++) {
        cout << bestSolution[i] << " ";
    }
    cout << endl;

    // Print the number of collisions in the optimal solution
    int optimalCollisions = calculateConflicts(bestSolution);
    cout << "Number of Collisions: " << optimalCollisions << endl;

    // Print the chessboard representation of the optimal solution
    cout << "Chessboard representation:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bestSolution[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

int main() {
    int n = 8;  // Number of queens (chessboard size)
    int maxIterations = 1000;  // Maximum number of iterations
    int tabuSize = 10;  // Size of the tabu list
    double w1 = 1.0;  // Weight for conflicts objective
    double w2 = 1.0;  // Weight for maximum distance objective

    solveNQueensTabuSearch(n, maxIterations, tabuSize, w1, w2);

    return 0;
}
