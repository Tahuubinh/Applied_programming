#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> c;
    for (auto u: a){
        int flag = 0;
        for (auto v: b){
            if (u.first == v.first){
                c[u.first] = max(u.second, v.second);
                flag = 1;
                break;
            }
        } 
        if (!flag){
            c[u.first] = u.second;
        }
    }
    for (auto u: b){
        int flag = 0;
        for (auto v: a){
            if (u.first == v.first){
                c[u.first] = max(u.second, v.second);
                flag = 1;
                break;
            }
        }
        if (!flag){
            c[u.first] = u.second;
        }
    }
    return c;
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> d;
    for (auto u: a){
        for (auto v: b){
            if (u.first == v.first){
                d[u.first] = min(u.second, v.second);
                break;
            }
        }
    }
    return d;
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    cout << "A = "; print_fuzzy_set(a);
    cout << "B = "; print_fuzzy_set(b);
    map<int, double> c = fuzzy_set_union(a, b);
    map<int, double> d = fuzzy_set_intersection(a, b);
    cout << "Union: "; print_fuzzy_set(c);
    cout << "Intersection: "; print_fuzzy_set(d);
}