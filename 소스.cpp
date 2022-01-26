#include<iostream>
#include<vector>
#include<string>
using namespace std;
string solution(vector<vector<int>> scores) {
    string answer;
    
    for (int i = 0; i < scores.size(); i++) {

        int temcnt = 0, temmean = 0, temsize = scores.size();

        for (int j = 0; j < temsize; j++) {
            if (scores[i][i] > scores[j][i]) {
                temcnt += 1;
            } else if (scores[i][i] < scores[j][i]) {
                temcnt -= 1;
            }
        }

        if (temcnt == temsize - 1 || temcnt == -temsize + 1) {
            scores[i][i] = 0;
            temsize += -1;
        }
        for (int j = 0; j < scores.size(); j++) {
            temmean += scores[j][i];
        }
        
        temmean = temmean / temsize;

        if (temmean >= 90) {
            answer += 'A';
        }
        else if (temmean >= 80) {
            answer += 'B';
        }
        else if (temmean >= 70) {
            answer += 'C';
        }
        else if (temmean >= 50) {
            answer += 'D';
        }
        else {
            answer += 'F';
        }

    }
    return answer;
}
int main()
{
    // main함수는 수정하지 않습니다.
    vector<vector<vector<int>>> scores = {
        {
            {100, 90, 98, 88, 65},
            {50, 45, 99, 85, 77},
            {47, 88, 95, 80, 67},
            {61, 57, 100, 80, 65},
            {24, 90, 94, 75, 65}
        },
        {
            {50, 90},
            {50, 87}
        },
        {
            {70, 49, 90},
            {68,50,38},
            {73,31,100}
        }
    };
    vector<string> result = {
        "FBABD",
        "DA",
        "CFD"
    };
    for (int i = 0; i < result.size(); i++)
    {
        if (solution(scores[i]) != result[i])
        {
            cout << "FAIL\n"; return 0;
        }
    }
    cout << "PASS\n"; return 0;
}