class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.empty()) return "Neither";
        if (IP.find('.') != -1 && IP.find(':') == -1 && ipv4Valid(IP)) return "IPv4";
        else if (IP.find(':') != -1 && IP.find('.') == -1 && ipv6Valid(IP)) return "IPv6";
        else return "Neither";
    }
    
    bool ipv4Valid(string IP) {
        stringstream ss(IP);
        string seg;
        int sz = 0;
        while (getline(ss, seg, '.')) {
            try { stol(seg);}
            catch (exception e) { return false;}
            if (seg.empty() || to_string(stol(seg)) != seg || stol(seg) < 0 || stol(seg) > 255) return false;
            sz++;
        }
        return sz == 4 && IP.back() != '.' ? true : false;
    }
    
    bool ipv6Valid(string IP) {
        stringstream ss(IP);
        string seg;
        int sz = 0;
        while (getline(ss, seg, ':')) {
            sz++;
            if (seg.size() < 1 || seg.size() > 4) return false;
            for (char c : seg) if (!isxdigit(c)) return false;
        }
        return sz == 8 && IP.back() != ':' ? true : false;
    }
};
