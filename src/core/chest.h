#pragma once

namespace diamant
{
    class chest
    {
        public:
            chest();

            const int get() const;
            void add(int diamonds);
            void clear();

        private:
            int diamonds;
    };
}