#include <iostream>
#include <fstream>
#include <vector>

//Список типовых свойств структуры данных «Граф»:
//1. {}Ориентированность.
//2. {}Связность.
//3. {}Взвешенность (реберная и вершинная, с наличием или отсутствием отрицательных весов).
//4. Раскраска (реберная и вершинная).
//5. {}Наличие кратных ребер и петель.
//6. {}Наличие циклов.
//7. {}Полнота.
//8. {}Дольность.

using namespace std;

ofstream file;

enum edgeColor{
    null,
    red,
    green,
    blue,

};

void write(vector<vector<int>> g1_matrix, vector<vector<int>> g1_list ){
    for (int i = 0; i < g1_matrix.size(); ++i) {
        for (int j = 0; j < g1_matrix[i].size(); ++j) {
            file << g1_matrix[i][j] << " ";
        }
        file << endl;
    }
    file << endl;
    for (int i = 0; i < g1_list.size(); ++i) {
        file << i + 1 << ": ";
        for (int j = 0; j < g1_list[i].size(); ++j) {
            file << g1_list[i][j] << " ";
        }
        file << endl;
    }
}
int main() {
    string str = "Полный связный невзвешенный граф";
    vector <vector<int>> g1_matrix = {
            {0, 1, 1, 1, 1, 1},
            {1, 0, 1, 1, 1, 1},
            {1, 1, 0, 1, 1, 1},
            {1, 1, 1, 0, 1, 1},
            {1, 1, 1, 1, 0, 1},
            {1, 1, 1, 1, 1, 0},
    };
    vector <vector<int>> g1_list = {
            {2, 3, 4, 5, 6},
            {1, 3, 4, 5, 6},
            {1, 2, 4, 5, 6},
            {1, 2, 3, 5, 6},
            {1, 2, 3, 4, 6},
            {1, 2, 3, 4, 5},
    };

    file.open("../g1.txt");
    if (file.is_open()){
        file << str << endl;
        write(g1_matrix, g1_list);
        file.close();
    }
    str = "Двудольный граф с наличием цикла";
    vector <vector<int>> g2_matrix = {
            {0, 0, 0, 1, 1, 0},
            {0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 1},
            {1, 1, 0, 0, 0, 0},
            {1, 0, 1, 0, 0, 0},
            {0, 1, 1, 0, 0, 0},
    };
    vector <vector<int>> g2_list = {
            {4, 5},
            {4, 6},
            {5, 6},
            {1, 2},
            {1, 3},
            {2, 3},
    };
    file.open("../g2.txt");
    if (file.is_open()){
        file << str << endl;
        write(g2_matrix, g2_list);
        file.close();
    }
    str = "Граф с наличием кратных ребер и петель";
    vector <vector<int>> g3_matrix = {
            {1, 2, 1, 2, 1, 1},
            {2, 0, 1, 1, 2, 1},
            {1, 1, 1, 1, 2, 1},
            {2, 1, 1, 0, 1, 1},
            {1, 2, 2, 1, 2, 1},
            {1, 1, 1, 1, 1, 0},
    };
    vector <vector<int>> g3_list = {
            {1, 2, 3, 4, 5, 6},
            {1, 3, 4, 5, 6},
            {1, 2, 3, 4, 5, 6},
            {1, 2, 3, 5, 6},
            {1, 2, 3, 4, 5, 6},
            {1, 2, 3, 4, 5},
    };
    file.open("../g3.txt");
    if (file.is_open()){
        file << str << endl;
        for (int i = 0; i < g3_matrix.size(); ++i) {
            for (int j = 0; j < g3_matrix[i].size(); ++j) {
                file << g3_matrix[i][j] << " ";
            }
            file << endl;
        }
        file << endl;
        for (int i = 0; i < g3_list.size(); ++i) {
            file << i + 1 << ": ";
            for (int j = 0; j < g3_list[i].size(); ++j) {
                file << g3_list[i][j] << "(" << g3_matrix[i][g3_list[i][j]-1]<< "), ";
            }
            file << endl;
        }
        file.close();
    }
    str = "Ориентированный реберно-взвешенный граф с отрицательными весами";
    vector <vector<int>> g4_matrix = {
            {0, 0, 0, 1, 1, 2},
            {1, 0, 0, 3, 4, -5},
            {0, 0, 1, 4, 2, -1},
            {0, 3, 3, 0, 0, 0},
            {1, 4, 5, 1, 0, 0},
            {0, -5, 1, 0, 0, 0},
    };
    vector <vector<int>> g4_list = {
            {4, 5, 6},
            {1, 4, 5, 6},
            {3, 4, 5, 6},
            {2, 3},
            {1, 2, 3, 4},
            {1, 2, 3},
    };
    file.open("../g4.txt");
    if (file.is_open()){
        file << str << endl;
        for (int i = 0; i < g4_matrix.size(); ++i) {
            for (int j = 0; j < g4_matrix[i].size(); ++j) {
                file << g4_matrix[i][j] << " ";
            }
            file << endl;
        }
        file << endl;
        for (int i = 0; i < g4_list.size(); ++i) {
            file << i + 1 << ": ";
            for (int j = 0; j < g4_list[i].size(); ++j) {
                file << g4_list[i][j] << "(" << g4_matrix[i][g4_list[i][j]-1]<< "), ";
            }
            file << endl;
        }
        file.close();
    }
    str = "Полный неориентированный граф с раскраской ребер";
    vector <vector <edgeColor>> g5_matrix = {
            {null, green, blue, red, blue},
            {green, null, blue, green, red},
            {blue, blue, null, red, green},
            {red, green, red, null, green},
            {blue, red, green, green, null}
    };
    vector <vector<int>> g5_list = {
            {2, 3, 4, 5},
            {1, 3, 4, 5},
            {1, 2, 4, 5},
            {1, 2, 3, 5},
            {1, 2, 3, 4}
    };
    file.open("../g5.txt");
    if (file.is_open()){
        file << str << endl;
        for (int i = 0; i < g5_matrix.size(); ++i) {
            for (int j = 0; j < g5_matrix[i].size(); ++j) {
                file << g5_matrix[i][j] << " ";
            }
            file << endl;
        }
        file << endl;
        for (int i = 0; i < g5_list.size(); ++i) {
            file << i + 1 << ": ";
            for (int j = 0; j < g5_list[i].size(); ++j) {
                file << g5_list[i][j] << "(" << g5_matrix[i][g5_list[i][j]-1]<< "), ";
            }
            file << endl;
        }
        file.close();
    }
}
