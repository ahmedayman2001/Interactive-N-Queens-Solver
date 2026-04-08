
#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define ld long double
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

// const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;


int n;
char grid_user[13][13];
vector<pair<int, int>> pos_user;
bool userWin = false;
int totalSolutions = 0; // counts all valid N-Queens solutions

//// ******************************************* ////

char grid [13][13] ;
vector <pair< int , int > > pos ;
bool queen [13] ;

// ------------------- Display user board -------------------
//// Display board in console ////

void displayBoard() {

    system("cls"); //// use "clear" if on Linux/macOS

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= n; ++j) {

            cout << grid_user[i][j] << " ";

        }
        cout << "\n";
    }
    cout << "\n";
}


// ------------------- Row-safety check for user -------------------

//// Check if it's safe to place a queen_user at (row, col) ////
bool isSafe(int row, int col) {

    //// row check (VERY IMPORTANT) ////
    for (int j = 1; j <= n; ++j) {

        if (grid_user[row][j] == 'Q')
            return false;
    }
    return true;
}




void displayGridAnimated() {

    system("cls"); // or "clear" on Linux/macOS

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= n; ++j) {

            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(200)); // pause 200ms

}



// ------------------------------------ Auto-solver without animation --------------------------------- //

void solve_Gen (int row ) {

    //// base case  ///
    if (row > n )
    {
        //// check if grid is valid ////

        bool valid = 1 ;

        for (int i = 0; i < pos.size() ; ++i) {

            for (int j = i+1; j < pos.size() ; ++j) {

                int x = abs(pos[i].first - pos[j].first) ;
                int y = abs (pos[i].second - pos[j].second );
                if (x== y )  ////
                    valid = 0 ;
            }
        }


        if ( valid ) {

            bool match = true;

            //// Increment counter ////
            totalSolutions ++ ;

            for ( int i = 1; i <= n && match; ++i ) {
                for (int j = 1; j <= n; ++j) {

                    if (grid_user[i][j] == 'Q' && grid[i][j] != 'Q') {
                        match = false;
                        break;
                    }
                }
            }



            if (match)
                userWin = true;

            //// Print all solutions  ////
            for (int i = 1; i <=n  ; ++i) {
                for (int j = 1; j <= n ; ++j) {

                    cout<<grid[i][j]<<" ";
                }
                cout<<el ;
            }
            cout << "-----------------\n";
        }

        return;
    }


    //// Transition ////
    for (int i = 1; i <= n; ++i) {

        //// check column is valid or not ///
        if ( queen[i] )
            continue ;
        queen[i] = 1 ;
        grid[row][i] = 'Q' ;
        pos.push_back({row , i} ) ;

        solve_Gen(row + 1) ;

        queen[i] = 0 ;
        grid[row][i] = '.' ;
        pos.pop_back() ;

    }
}


// ---------------------------- Auto-solver with animation --------------------------------------------------------- //


void solve_Animation (int row ) {

    //// base case  ///
    if (row > n )
    {
        //// check if grid is valid ////

        bool valid = 1 ;

        for (int i = 0; i < pos.size() ; ++i) {

            for (int j = i+1; j < pos.size() ; ++j) {

                int x = abs(pos[i].first - pos[j].first) ;
                int y = abs (pos[i].second - pos[j].second );
                if (x== y )  ////
                    valid = 0 ;
            }
        }


        if ( valid ) {

            bool match = true;

            //// Increment counter ////
            totalSolutions++ ;

            for ( int i = 1; i <= n && match; ++i ) {
                for (int j = 1; j <= n; ++j) {

                    if (grid_user[i][j] == 'Q' && grid[i][j] != 'Q') {
                        match = false;
                        break;
                    }
                }
            }


            if (match)
                userWin = true;

            //// Print solution animation ////
            displayGridAnimated();
            cout << "-----------------\n";
        }

        return;
    }


    //// Transition ////
    for (int i = 1; i <= n; ++i) {

        //// check column is valid or not ///
        if ( queen[i] )
            continue ;
        queen[i] = 1 ;
        grid[row][i] = 'Q' ;
        pos.push_back({row , i} ) ;
        displayGridAnimated() ;

        solve_Animation(row + 1) ;

        queen[i] = 0 ;
        grid[row][i] = '.' ;
        pos.pop_back() ;

        displayGridAnimated();
    }
}



// ----------------------------------- Interactive mode --------------------------------------------------//


//// Interactive command interface ////

void interactiveMode() {

    pos_user.clear();

    for (int i = 1; i <= n; ++i)

        for (int j = 1; j <= n; ++j)

            grid_user[i][j] = '.';


    string cmd;

    while (true) {

        displayBoard();

        cout << "Commands: place row col | remove row | solve_Animation | solve_Gen |  reset | exit\n";

        cout << "Enter command: ";

        cin >> cmd;



        if (cmd == "place") {

            int r, c;
            cin >> r >> c;

            if (r < 1 || r > n || c < 1 || c > n) {
                cout << "Invalid position!\n";
                continue;

            }

            if (isSafe(r, c)) {

                grid_user[r][c] = 'Q';

                pos_user.push_back({r, c});

            } else {

                cout << "Conflict! Cannot place queen_user.\n";
            }


        }





        else if (cmd == "remove") {

            int r; cin >> r;

            if (r < 1 || r > n) {

                cout << "Invalid row!\n";

                continue;
            }

            for (int i = 1; i <= n; ++i) {

                if (grid_user[r][i] == 'Q') {
                    grid_user[r][i] = '.';
                    break;
                }
            }

            for (int i = 0; i < pos_user.size(); ++i) {

                if (pos_user[i].first == r) {
                    pos_user.erase(pos_user.begin() + i);

                    break;
                }
            }

        }




        else if (cmd == "solve_Animation") {

            //// 1- reset Increment  ////
            totalSolutions = 0 ;
            //// 2- reset auto-solver state ////
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    grid[i][j] = '.';

            fill(queen+1, queen +n+1, 0);
            pos.clear();


            //// 3- reset result flag ////
            userWin = false;


            //// 4-  generate all solutions ////
            solve_Animation(1);


            //// 5- generate total no.of solutions ////
            cout << "Total valid solutions for N = " << n << " is: " << totalSolutions << "\n";


            //// 5- final result ////
            if (userWin)


                cout << " True You Win!\n ";

            else

                cout << " You Lose Wrong Solution : Tray again Please \n ";

            system("pause");   //// optional (Windows) ////

        }




        else if ( cmd == "solve_Gen" ) {

            //// 1- reset Increment  ////
            totalSolutions = 0 ;

            //// 2- reset auto-solver state ////
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    grid[i][j] = '.';

            fill(queen+1, queen +n+1, 0);
            pos.clear();


            //// 3- reset result flag ////
            userWin = false;


            //// 4-  generate all solutions ////
            solve_Gen(1);

            cout << "Total valid solutions for N = " << n << " is: " << totalSolutions << "\n";


            //// 5- final result ////
            if (userWin)


                cout << " True You Win!\n ";

            else

                cout << " You Lose Wrong Solution : Tray again Please \n ";

            system("pause");   //// optional (Windows) ////

        }



        else if (cmd == "reset") {

            pos_user.clear();

            for (int i = 1; i <= n; ++i)

                for (int j = 1; j <= n; ++j)

                    grid_user[i][j] = '.';
        }



        else if (cmd == "exit") {

            break;
        }


        else {

            cout << "Unknown command!\n";
        }


    }
}


// ------------------------------------- Main -------------------------------------------------------------------//

int main() {

    cout << "\n============================================\n";
    cout << "N-Queens Puzzle"<<el;
    cout << "============================================\n";
    cout << "Try to place " << n << " queens on this chessboard.\n";
    cout << " Rules:\n ";
    cout << " Place exactly ONE queen in each row.\n";
    cout << " No two queens may attack each other.\n";
    cout << " Queens must NOT share the same row, column, or diagonal.\n";
    cout << "\nYour task is to find a valid configuration.\n";
    cout << "Use the available commands to place or remove queens.\n";
    cout << "When you are done, type 'solve_Animation' to check your solution.\n";
    cout << "Or type 'solve_Gen' to generate all possible solutions as static visualizations.\n";
    cout << "============================================\n\n";

    // ------------------- Input validation ----------------------------------------------- //

    while (true) {

        cout << "Enter N: Size of chessboard for N-Queens Puzzle (4 to 12): ";
        cin >> n;

        if (n < 4) {
            cout << "N too small! No valid solutions exist for N < 4.\n";
        }
        else if (n > 12) {
            cout << "N too large! This will likely TLE because the complexity is O(N!).\n";
        }
        else {

            cout << "Great! You chose N = " << n << ". Let's play!"<<el;

            break; // valid input
        }
    }

    interactiveMode();


    return 0 ;

}









