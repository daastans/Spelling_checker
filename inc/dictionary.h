#include<string>
#include<set>

class Dictionary
{
private:
  std::set<std::string> mWords;
public:
  Dictionary(const std::string &fname)
  {
      mWords.insert("dog");
  };
  bool check(const std::string &word) const
  {
    return mWords.find(word)!=mWords.end();
  };
};
