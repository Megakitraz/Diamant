#pragma once

namespace diamant
{
    class chest
    {
        public:
            chest();

            void add(int diamonds);
            void clear();

        private:
            int diamonds;

    };
}