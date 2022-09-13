using namespace std;
class Singleton{
public:
    static Singleton *getInstance();
private:
    static Singleton *m_Instance;
    static pthread_mutex_t mutex;
    Singleton();
    ~Singleton();
    Singleton(const Singleton &s);
    const Singleton operator=(const Singleton &s);
};
Singleton* Singleton::m_Instance = nullptr;
pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;
Singleton *Singleton::getInstance(){
    if(m_Instance == nullptr) {
        pthread_mutex_t(&mutex);
        if (m_Instance == nullptr) {
            Singleton *tmp = new Singleton();
            m_Instance = tmp;
        }
    }
    return m_Instance;
}
