namespace targets {
// TODO: Insert the code for the alien class here
    class Alien {
        public:
            Alien(int x, int y) : x_coordinate(x), y_coordinate(y), health(3) {
            }
            int get_health() const { return health; }
            bool hit() {
                if (health > 0) --health;
                return true;
            }
            bool is_alive() {
                return health > 0 ? true : false;
            }
            bool teleport(int x_new, int y_new) {
                x_coordinate = x_new;
                y_coordinate = y_new;
                return true;
            }
            bool collision_detection(const Alien alien) {
                if (alien.x_coordinate == x_coordinate &&
                    alien.y_coordinate == y_coordinate) {
                    return true;
                }
                return false;
            }
            int x_coordinate;
            int y_coordinate;
        private:
            int health;
    };
}  // namespace targets
