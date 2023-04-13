#pragma once

namespace diamant
{

	class lobby
	{
		public:
			int get_player_count() const;
			int get_round_count() const;

			void set_player_count(int new_player_count);
			void set_round_count(int new_round_count);

		private:
			int player_count = 1;
			int round_count = 1;
	};

}