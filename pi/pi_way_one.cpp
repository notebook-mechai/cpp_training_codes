#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;

// مبنای اعداد بزرگ (هر بلوک ۹ رقم اعشار را در خود جای می‌دهد)
const int BASE = 1000000000;
const int BASE_DIGITS = 9;

// کلاس مدیریت اعداد بزرگ (BigInt)
struct BigInt {
    vector<int> z; // ذخیره ارقام به صورت معکوس (کم‌ارزش‌ترین بخش در ابتدا)
    bool neg;

    BigInt() : neg(false) {}
    
    BigInt(long long v) {
        if (v < 0) { neg = true; v = -v; }
        else neg = false;
        while (v > 0) {
            z.push_back(v % BASE);
            v /= BASE;
        }
    }

    // ضرب عدد بزرگ در یک عدد کوچک
    void mul(long long v) {
        if (v == 0) { z.clear(); return; }
        long long carry = 0;
        for (size_t i = 0; i < z.size() || carry; ++i) {
            if (i == z.size()) z.push_back(0);
            long long cur = carry + z[i] * 1LL * v;
            z[i] = cur % BASE;
            carry = cur / BASE;
        }
        trim();
    }

    // تقسیم عدد بزرگ بر یک عدد کوچک
    void div(long long v) {
        if (v == 0) throw runtime_error("Division by zero");
        long long carry = 0;
        for (int i = (int)z.size() - 1; i >= 0; --i) {
            long long cur = z[i] + carry * BASE;
            z[i] = cur / v;
            carry = cur % v;
        }
        trim();
    }

    // جمع دو عدد بزرگ مثبت
    void add(const BigInt& o) {
        int carry = 0;
        for (size_t i = 0; i < max(z.size(), o.z.size()) || carry; ++i) {
            if (i == z.size()) z.push_back(0);
            long long sum = (i < o.z.size() ? o.z[i] : 0) + z[i] + carry;
            z[i] = sum % BASE;
            carry = sum / BASE;
        }
        trim();
    }

    // تفریق دو عدد بزرگ مثبت (با فرض اینکه عدد اول بزرگتر یا مساوی است)
    void sub(const BigInt& o) {
        int carry = 0;
        for (size_t i = 0; i < o.z.size() || carry; ++i) {
            long long diff = z[i] - carry - (i < o.z.size() ? o.z[i] : 0);
            if (diff < 0) {
                diff += BASE;
                carry = 1;
            } else {
                carry = 0;
            }
            z[i] = diff;
        }
        trim();
    }

    // حذف صفرهای اضافی از ابتدای عدد
    void trim() {
        while (!z.empty() && z.back() == 0) z.pop_back();
        if (z.empty()) neg = false;
    }

    bool isZero() const { return z.empty(); }

    // تبدیل عدد بزرگ به رشته متنی
    string toString() const {
        if (z.empty()) return "0";
        string s;
        if (neg) s += "-";
        s += to_string(z.back());
        for (int i = (int)z.size() - 2; i >= 0; --i) {
            stringstream ss;
            ss << setw(BASE_DIGITS) << setfill('0') << z[i];
            s += ss.str();
        }
        return s;
    }
};

// تابع ساخت عدد ۱۰ به توان D
BigInt pow10(int D) {
    BigInt res;
    int num_blocks = D / BASE_DIGITS;
    int rem = D % BASE_DIGITS;
    res.z.resize(num_blocks + 1, 0);
    long long val = 1;
    for(int i = 0; i < rem; ++i) val *= 10;
    res.z[num_blocks] = val;
    return res;
}

// محاسبه آرک‌تانژانت با استفاده از بسط تیلور
BigInt arctan(int k, int D) {
    BigInt term = pow10(D);
    term.div(k);
    
    BigInt sum = term;
    int n = 1;
    long long k2 = 1LL * k * k;
    
    while (true) {
        term.mul(2 * n - 1);
        term.div(k2 * (2 * n + 1));
        if (term.isZero()) break;
        
        if (n % 2 != 0) sum.sub(term);
        else sum.add(term);
        n++;
    }
    return sum;
}

// تابع اصلی محاسبه و ذخیره عدد پی
void calculate_and_save_pi(int digits, const string& filename = "pi_digits.txt") {
    if (digits < 0) {
        cout << "تعداد ارقام نمی‌تواند منفی باشد.\n";
        return;
    }

    // تنظیم رقم محافظ (Guard digits) برای جلوگیری از خطای گرد کردن
    int D = digits + 15; 

    cout << "در حال محاسبه عدد پی تا " << digits << " رقم...\n";
    
    // محاسبه بر اساس فرمول ماچین
    BigInt pi_val = arctan(5, D);
    pi_val.mul(16);
    
    BigInt sub_val = arctan(239, D);
    sub_val.mul(4);
    
    pi_val.sub(sub_val);

    // تبدیل به رشته و تنظیم ممیز اعشار
    string pi_str = pi_val.toString();
    if (digits == 0) {
        pi_str = "3";
    } else {
        if (pi_str.length() > 1) {
            pi_str.insert(1, ".");
        }
        // برش دادن ارقام اضافی
        if (pi_str.length() > (size_t)(digits + 2)) {
            pi_str = pi_str.substr(0, digits + 2);
        }
    }

    // ذخیره در فایل
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "عدد پی تا " << digits << " رقم اعشار:\n\n";
        outFile << pi_str;
        outFile.close();
        cout << "✅ عملیات با موفقیت انجام شد!\n";
        cout << "عدد پی در فایل '" << filename << "' ذخیره شد.\n";
    } else {
        cout << "❌ خطا در باز کردن فایل برای نوشتن.\n";
    }
}

int main() {
    // بهبود ظاهر کنسول برای نمایش حروف فارسی در ویندوز (اختیاری)
    #ifdef _WIN32
    system("chcp 65001 >nul");
    #endif

    int num_digits;
    cout << "چند رقم از عدد پی را می‌خواهید محاسبه و ذخیره کنید؟ ";
    
    if (cin >> num_digits) {
        calculate_and_save_pi(num_digits);
    } else {
        cout << "لطفاً یک عدد صحیح و معتبر وارد کنید.\n";
    }

    return 0;
}
