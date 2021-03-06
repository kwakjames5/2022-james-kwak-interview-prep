class Solution {
public:
    vector<double> sampleStats(vector<int>& cnts) {
      double res[5] = { 255, 0, 0, 0, 0 };
      int t_cnt = accumulate(begin(cnts), end(cnts), 0), m_cnt = 0;
      int m1 = (t_cnt + 1) / 2, m2 = m1 + (t_cnt % 2 == 0 ? 1 : 0);
      for (auto i = 0, cnt = 0; i < cnts.size(); cnt += cnts[i++]) {
        res[0] = cnts[i] ? min((int)res[0], i) : res[0];
        res[1] = cnts[i] ? i : res[1];
        res[2] += (double)i * cnts[i] / t_cnt;

        if (cnt < m1 && cnt + cnts[i] >= m1) res[3] += (double)i / 2;
        if (cnt < m2 && cnt + cnts[i] >= m2) res[3] += (double)i / 2;

        res[4] = m_cnt < cnts[i] ? i : res[4];
        m_cnt = max(m_cnt, cnts[i]);
      }
      return vector<double>(begin(res), end(res));
    }
};