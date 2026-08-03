class Foo {
    std::condition_variable cv;
    std::mutex m;
    int next = 1;

public:
    Foo() {}

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        next = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock glock(m);
        cv.wait(glock, [this]() { return next == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        next = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {

        // printThird() outputs "third". Do not change or remove this line.
        std::unique_lock lk(m);
        cv.wait(lk, [this]() { return next == 3; });
        printThird();
    }
};