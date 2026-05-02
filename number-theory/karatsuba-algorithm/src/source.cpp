#include <iostream>
#include <vector>

void multiply (const std::vector<int>& x, const std::vector<int>& y, std::vector<int>& z, int base) {
    for (size_t i = 0; i < x.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < y.size(); ++j) {
            long long int cur = z[i + j] + 1LL * x[i] * y[j] + carry;
            z[i + j] = cur % base;
            carry = cur / base;
        }
        z[i + y.size()] += carry;
    }
    while (z.size() > 1 && z.back() == 0) {
        z.pop_back();
    }
}

std::string padLeft(std::string s, int n) {
    while ((int)s.size() < n) s = "0" + s;
    return s;
}

long long karatsuba(long long X, long long Y);

long long karatsuba_string(std::string Xs, std::string Ys) {
    size_t n = std::max(Xs.size(), Ys.size());
    if (n == 1) {
        return (Xs[0] - '0') * (Ys[0] - '0');
    }

    Xs = padLeft(Xs, n);
    Ys = padLeft(Ys, n);

    size_t m = n / 2;

    long long Xl = stoll(Xs.substr(0, n - m));
    long long Xr = stoll(Xs.substr(n - m));
    long long Yl = stoll(Ys.substr(0, n - m));
    long long Yr = stoll(Ys.substr(n - m));

    long long P1 = karatsuba(Xl, Yl);
    long long P2 = karatsuba(Xr, Yr);
    long long P3 = karatsuba(Xl + Xr, Yl + Yr);
    
    long long p10 = 1;
    for (size_t i = 0; i < m; ++i) {
        p10 *= 10;
    }

    return P1 * p10 * p10
         + (P3 - P1 - P2) * p10
         + P2;
}

long long karatsuba(long long X, long long Y) {
    if (X < 10 || Y < 10) {
        return X * Y;
    }
    return karatsuba_string(std::to_string(X), std::to_string(Y));
}

int main() {

    std::vector<int> a = {4, 3, 2, 1};
    std::vector<int> b = {8, 7, 6, 5};
    std::vector<int> c(a.size() + b.size());
    int base = 10;

    multiply(a, b, c, base);

    for (int i = c.size() - 1; i >= 0; --i) {
        std::cout << c[i];
    }
    std::cout << std::endl;

    long long X = 123, Y = 4567;
    std::cout << karatsuba(X, Y) << std::endl;

    return 0;
}