//defines macros for program version
#define OpenCQT_MAJOR 0
#define OpenCQT_MINOR 1
#if defined(_WIN64) || defined(_WIN32)
#define OpenCQT_VERSION L"0.1"
#else
#define OpenCQT_VERSION "0.1"
#endif


#include <string>
//@formatter:off&!off
namespace OpenCqt {
#if defined(_WIN64) || defined(_WIN32)
	static const std::wstring getVersion() {
#else
	static const std::string getVersion() {
#endif
		return OpenCQT_VERSION;
	}
}
//@formatter:on&!on
