#include <iostream>
#include <functional>
#include <cmath>

#define GET(...) #__VA_ARGS__, __VA_ARGS__
#define RUN(...) #__VA_ARGS__, [&](){ __VA_ARGS__ }()
#define FUN(...) #__VA_ARGS__, [&](){ __VA_ARGS__ }

// template <typename T>
class Verify {
	size_t fails_ = 0;
	size_t tests_ = 0;
public:
	Verify(std::string name) {
		std::cout << ":" << name << ":\n";
	}
	void Total() {
		std::cout << " === Total: " << tests_ - fails_ << "/" << tests_ 
				<< " (" << std::round((tests_ - fails_) / (float)tests_ * 100) << "%) ===\n\n";
	}
	template <typename T>
	bool Assert(std::string msg, const T& res, const T& expect) {
		using std::cout;
		using std::endl;

		++tests_;
		bool fail = res != expect;
		cout << "  ☼ Test " << tests_;
		if (fail) {
			cout << " ×××FAIL×××\n"
					 << "\t→ run: " << msg << "\n"
					 << "\t× returned: '" << res << "'\n" 
					 << "\t√ expected: '" << expect << "'\n";
			++fails_;
		}
		else {
			cout << " √";
		}
		cout << endl;

		return !fail;
	}
	bool Assert(std::string msg, bool res) {
		return Assert<bool>(msg, res, true);
	}
	template <typename T>
	bool Run(std::string msg, std::function<T()> f, const T& expect) {
		return Assert(msg, f(), expect);
	}
	bool Try(std::string msg, std::function<void()> f, std::string expect) {
		return Run<std::string>("try { "+msg+" }", [&]() {
			try{
				f();
				return std::string("OK");
			}
			catch(int err){
				return std::to_string(err);
			}
			catch(const char* err){
				return std::string(err);
			}
			catch(std::string err) {
				return err;
			}
			catch(std::exception& err) {
				return std::string(err.what());
			}
		}, expect);
	}
	
};