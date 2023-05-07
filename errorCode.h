#ifndef __HAVE_OMIKUJI_ERRORCODE_H__
#define __HAVE_OMIKUJI_ERRORCODE_H__

namespace omikuji {
enum class Error {
	NONE = 0,
	BREAK_BOX = -1,
	STUCKKED = -2,
};
}

#endif // __HAVE_OMIKUJI_ERRORCODE_H__