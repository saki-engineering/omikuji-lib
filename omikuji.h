#ifndef __HAVE_OMIKUJI_ITF_H__
#define __HAVE_OMIKUJI_ITF_H__

namespace omikuji {
struct Paper {
	char* status;
	char* description;

	Paper () {
		status = "小吉";
		description = "いつもどおり";
	};
	Paper (char* _status, char* _description);
};

class OmikujiItf {
public:
	OmikujiItf(void) {};
	virtual ~OmikujiItf(void) {};

	virtual Error DrawStatus(char** status) = 0;
	virtual Error DrawPaper(Paper* paper) = 0;
	virtual Error MultiDrawPaper(Paper *paper, int n) = 0;

	static OmikujiItf* CreateBox(void);
};

}
#endif // __HAVE_OMIKUJI_ITF_H__