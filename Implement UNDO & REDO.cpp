class Solution {
    int curr = -1;
    vector<char> v;
  public:
    void append(char x) {
        // append x into document
        while(curr < (int)v.size() - 1) v.pop_back();
        v.push_back(x); curr++;
    }

    void undo() {
        // undo last change
        if(curr >= 0) curr--;
    }

    void redo() {
        // redo changes
        if(curr < (int)v.size() - 1) curr++;
    }

    string read() {
        // read the document
        string res = "";
        for(int i(0);i <= curr;i++) res += v[i];
        return res;
    }
};
