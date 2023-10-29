#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

struct Node {
    int row, col;
    Node(int r, int c) : row(r), col(c) {}
};

void findPaths(vector<vector<int>>& grid, vector<Node>& path, vector<vector<Node>>& allPaths, vector<Node>& shortestPath, int& minPathSum, int row, int col, int currentSum) {
    int m = grid.size();
    int n = grid[0].size();

    if (row == m - 1 && col == n - 1) {
        //到達終點的路線加入allpaths
        allPaths.push_back(path);
        if (currentSum < minPathSum) {
            minPathSum = currentSum;
            shortestPath = path;
        }
        return;
    }

    // 向右
    if (col + 1 < n) {
        path.push_back(Node(row, col + 1));
        findPaths(grid, path, allPaths, shortestPath, minPathSum, row, col + 1, currentSum + grid[row][col + 1]);
        path.pop_back();
    }

    // 向下
    if (row + 1 < m) {
        path.push_back(Node(row + 1, col));
        findPaths(grid, path, allPaths, shortestPath, minPathSum, row + 1, col, currentSum + grid[row + 1][col]);
        path.pop_back();
    }
}

int main() {
    vector<vector<int>> grid;

    string input;
    cout << "請輸入一個二維陣列:";
    getline(cin, input);

    stringstream ss(input);
    char opening_bracket, closing_bracket;
    char comma;
    vector<vector<int>> twoDArray;

    ss >> opening_bracket; 
    while (ss >> opening_bracket) {
        if (opening_bracket == ']') {
            break;
        }

        vector<int> row;
        do {
            int value;
            ss >> value;
            row.push_back(value);
            ss >> comma;
        } while (comma == ',');

        twoDArray.push_back(row);
        ss >> closing_bracket;

        if (ss.peek() == ',') {
            ss.get();
        }
    }

    grid = twoDArray;
    int m = grid.size();
    int n = grid[0].size();


    vector<vector<Node>> allPaths;//起點到終點,探訪過路徑
    vector<Node> path;//當前路徑
    path.push_back(Node(0, 0));//初始化

    vector<Node> shortestPath;
    int minPathSum = INT_MAX;

    findPaths(grid, path, allPaths, shortestPath, minPathSum, 0, 0, grid[0][0]);

    cout << "數字地圖:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "       [";
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << "]";
        cout << endl;
    }
    if (m + n < 8) {
        cout << "所有路徑:" << endl;
        for (const auto& path : allPaths) {
            cout << "      [";
            for (const Node& node : path) {
                cout << grid[node.row][node.col] << " ";
            }
            cout << "]";
            cout << endl;
        }
    }
    cout << "最小路徑:";
    cout << "  [";
    for (const Node& node : shortestPath) {
        cout << grid[node.row][node.col] << " ";
    }
    cout << "]";
    cout << endl;

    cout << "最小路徑和:  " << minPathSum << endl;

    return 0;
}
