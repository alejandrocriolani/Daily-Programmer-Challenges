#include <iostream>
using std::cout;

#include <set>
using std::set;

#include <vector>
using std::vector;

int abs(int n)
{
    if(n < 0)
        return -n;
    return n;
}

bool allZero(vector<int> seq)
{
    for(int i = 0; i < seq.size(); i++)
    {
        if(seq[i] != 0)
            return false;
    }
    return true;
}

void printSeq(const vector<int> & seq)
{
    cout << "< ";
    for(int i = 0; i < seq.size(); i++)
    {
        cout << seq[i] << ", ";
    }
    cout << ">\n";
}

void ducciSequence(vector<int> seq)
{
    set<vector<int>> checked {};
    int steps = 1;
    cout << "Seq: ";
    printSeq(seq);
    while(!allZero(seq))
    {
        if(checked.count(seq) != 0)
            break;
        vector<int> auxSeq = seq;
        checked.insert(seq);
        for(int i = 0; i < seq.size(); i++)
        {
            if(i == seq.size() - 1)
            {
                seq[i] = abs(auxSeq[i] - auxSeq[0]);
            }
            else
            {
                seq[i] = abs(auxSeq[i] - auxSeq[i+1]);
            }
        }
        ++steps;
        cout << "Step: " << steps << "\n";
        printSeq(seq);
    }
}

int main()
{
    cout << "------------ Sequence 1 ------------\n";
    vector<int> seq1 {0, 653, 1854, 4063};
    ducciSequence(seq1);
    cout << "------------ Sequence 2 ------------\n";
    vector<int> seq2 {1, 5, 7, 9, 9};
    ducciSequence(seq2);
    cout << "------------ Sequence 3 ------------\n";
    vector<int> seq3 {1,2,1,2,1,0};
    ducciSequence(seq3);
    cout << "------------ Sequence 4 ------------\n";
    vector<int> seq4 {10, 12, 41, 62, 31, 50};
    ducciSequence(seq4);
    cout << "------------ Sequence 5 ------------\n";
    vector<int> seq5 {10, 12, 41, 62, 31};
    ducciSequence(seq5);
    
    return 0;
}