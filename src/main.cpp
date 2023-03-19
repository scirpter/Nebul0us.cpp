#include "net/DataInputStream.h"
#include "net/DataOutputStream.h"
#include "models/World.h"

#define LOG(msg) std::cout << msg << std::endl

int main()
{
    std::unique_ptr<models::World> world = std::make_unique<models::World>();

    world->m_name = "Testz";

    LOG("World name: " << world->m_time_left);

    std::cin.get();
}