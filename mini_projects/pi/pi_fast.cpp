#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#include <string>
#include <fstream>
#include <gmpxx.h>

using namespace std;

// ساختار بازگشتی برای الگوریتم Binary Splitting
struct BSResult {
    mpz_class P, Q, T;
};

// تابع اصلی تقسیم و غلبه دودویی برای الگوریتم چودنوفسکی
BSResult chudnovsky_bs(int a, int b) {
    if (b - a == 1) {
        if (a == 0) {
            return {mpz_class(1), mpz_class(1), mpz_class(13591409)};
        }
        mpz_class k(a);

        // p_k = (6k-5)(2k-1)(6k-1)
        mpz_class p = (6 * k - 5) * (2 * k - 1) * (6 * k - 1);

        // q_k = k^3 * 10939058860032000
        // استفاده از رشته برای جلوگیری از مشکل overflow در long ویندوز
        mpz_class C("10939058860032000");
        mpz_class q = k * k * k * C;

        // t_k = (545140134*k + 13591409) * p_k
        mpz_class t = (545140134L * k + 13591409L) * p;

        // اعمال علامت متناوب (-1)^k
        if (a % 2 != 0) {
            t = -t;
        }
        return {p, q, t};
    }

    int m = a + (b - a) / 2;
    BSResult left  = chudnovsky_bs(a, m);
    BSResult right = chudnovsky_bs(m, b);

    BSResult res;
    res.P = left.P * right.P;
    res.Q = left.Q * right.Q;
    res.T = left.T * right.Q + right.T * left.P;
    return res;
}

void calculate_pi_fast(int digits, const string& filename = "pi_fast.txt") {
    if (digits <= 0) {
        cout << "تعداد ارقام باید بزرگتر از صفر باشد.\n";
        return;
    }

    cout << "در حال آماده‌سازی محاسبات برای " << digits << " رقم...\n";

    // هر جمله در سری چودنوفسکی حدود 14.18 رقم اعشار اضافه می‌کند
    int num_terms = digits / 14 + 2;

    cout << "تعداد جملات مورد نیاز: " << num_terms << "\n";
    cout << "در حال محاسبه سری چودنوفسکی (Binary Splitting)...\n";

    // اجرای الگوریتم Binary Splitting
    BSResult res = chudnovsky_bs(0, num_terms);

    cout << "محاسبه سری تمام شد. در حال تبدیل به عدد اعشاری...\n";

    // تنظیم دقت شناور بر حسب بیت
    // هر رقم اعشار ≈ 3.3219 بیت + 128 بیت محافظ
    int bits_precision = static_cast<int>(digits * 3.321928094887362) + 128;
    mpf_set_default_prec(bits_precision);

    // محاسبه sqrt(1823211888768000)
    // این عدد برابر است با 640320^3 / 144
    mpz_class M_str("1823211888768000");
    mpf_class sqrt_M(M_str);
    mpf_sqrt(sqrt_M.get_mpf_t(), sqrt_M.get_mpf_t());

    // تبدیل صورت و مخرج نهایی به شناور با دقت بالا
    mpf_class Q_mp(res.Q);
    mpf_class T_mp(res.T);

    // π = sqrt(1823211888768000) * Q / T
    mpf_class pi = sqrt_M * (Q_mp / T_mp);

    cout << "در حال نوشتن در فایل " << filename << "...\n";

    ofstream outFile(filename);
    if (outFile.is_open()) {
        // get_str یک رشته بدون نقطه اعشار برمی‌گرداند
        // و expo را طوری تنظیم می‌کند که: مقدار = 0.rstr × 10^expo
        mp_exp_t expo;
        string pi_str = pi.get_str(expo, 10, digits + 2);

        // درج نقطه اعشار در موقعیت صحیح
        if (expo > 0) {
            if (static_cast<size_t>(expo) < pi_str.length()) {
                pi_str.insert(static_cast<size_t>(expo), ".");
            } else {
                pi_str.append(static_cast<size_t>(expo) - pi_str.length(), '0');
                pi_str += ".0";
            }
        } else {
            pi_str = "0." + string(static_cast<size_t>(-expo), '0') + pi_str;
        }

        outFile << pi_str;
        outFile.close();

        cout << "✅ عملیات با موفقیت انجام شد!\n";
        cout << "عدد پی تا " << digits << " رقم در فایل '" << filename << "' ذخیره شد.\n";
    } else {
        cout << "❌ خطا در باز کردن فایل برای نوشتن.\n";
    }
}

int main() {
    #ifdef _WIN32
    system("chcp 65001 >nul");
    #endif

    int num_digits;
    cout << "چند رقم از عدد پی را می‌خواهید محاسبه کنید؟ (پیشنهاد: ابتدا 100000): ";

    if (cin >> num_digits) {
        calculate_pi_fast(num_digits);
    } else {
        cout << "لطفاً یک عدد صحیح و معتبر وارد کنید.\n";
    }

    return 0;
}
