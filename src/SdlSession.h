#pragma once

class SdlSession
{
	public:
		SdlSession();
		~SdlSession();
		bool init();
	private:
		bool initialized;
		bool ttfInitialized;
};
