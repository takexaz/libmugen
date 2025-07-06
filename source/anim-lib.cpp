#include <cassert>

const char ASSERTFAILURE = "Assert failure in %s line %i";
const char FILE_ANIMLIB = ""


int AnimCurElemStartTime(Anim* anim, int elem) {
	if (!anim || !(anim->useAnimRCArrayEx) || !(anim->useAnimRCArrayEx->animData)) {
		sprintf(ErrorMessageBuf, ASSERTFAILURE, "anim-lib.cpp", 887);
		DebugErrorExit(ErrorMessageBuf);
	}
}
