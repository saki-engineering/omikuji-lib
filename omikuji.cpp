#include "errorCode.h"
#include "omikuji.h"
#include <vector>
#include <random>

omikuji::Paper::Paper(char* _status, char* _description) {
	status = _status;
	description = _description;
}

class Omikuji : public omikuji::OmikujiItf {
public:
	Omikuji() {
		omikuji::Paper data[] = {
			omikuji::Paper("大吉", "超ラッキー！！"),
			omikuji::Paper("吉", "いいことあるかも！"),
			omikuji::Paper("吉", "ついてる！"),
			omikuji::Paper("中吉", "良さげ"),
			omikuji::Paper("中吉", "いい感じ"),
			omikuji::Paper("中吉", "まあまあ"),
			omikuji::Paper("小吉", "普通"),
			omikuji::Paper("小吉", "そこそこ"),
			omikuji::Paper("小吉", "可もなく不可もなく"),
			omikuji::Paper("小吉", "いつもどおり"),
			omikuji::Paper("末吉", "そういう日もある"),
			omikuji::Paper("末吉", "ついてないかも"),
			omikuji::Paper("末吉", "うーん"),
			omikuji::Paper("凶", "ついてないね"),
			omikuji::Paper("凶", "ダメかも"),
			omikuji::Paper("大凶", "今日は何をやってもダメ")
		}; 
		std::vector<omikuji::Paper> _box(data, std::end(data)); 
		box = _box;
	};
	omikuji::Error DrawStatus(char** status) {
		omikuji::Paper paper;
		omikuji::Error result = DrawPaper(&paper);

		if (result != omikuji::Error::NONE) {
			return result;
		}
		*status = paper.status;
		return omikuji::Error::NONE;
	};

	omikuji::Error DrawPaper(omikuji::Paper* paper) {
		float p = UniDist();
		if (p < 0.01) {
			return omikuji::Error::BREAK_BOX;
		} else if (p < 0.02) {
			return omikuji::Error::STUCKKED;
		}

		*paper = box[Rand()];
		return omikuji::Error::NONE;
	};

	omikuji::Error MultiDrawPaper(omikuji::Paper *paper, int n) {
		return omikuji::Error::NONE;
	};

private:
	std::vector<omikuji::Paper> box;
	int Rand(void) {
		int n = box.size();

		std::random_device rnd;
		std::mt19937 mt(rnd());
		std::uniform_int_distribution<> randIdx(0, n-1);
		return randIdx(mt);
	};
	float UniDist(void) {
		std::random_device rnd;
		std::mt19937 mt(rnd());
		std::uniform_real_distribution<double> uni(0, 1);
		return uni(mt);
	};
};

omikuji::OmikujiItf* omikuji::OmikujiItf::CreateBox(void) {
	return new Omikuji();
}
