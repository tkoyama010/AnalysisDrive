/**
 * @file   JsonValueBool.h
 * @brief  JSONの値(bool)
 * @author kyo
 * @date   2015/05/05
 */
#ifndef ANALYSISDRIVE_JSONVALUEBOOL_H_
#define ANALYSISDRIVE_JSONVALUEBOOL_H_

#include "JsonValue.h"
#include "Json.h"
#include "IncludeMsgpack.h"

/** Analysis Drive */
namespace adlib
{
/** JSONの値(bool) */
class JsonValueBool final : public JsonValue
{
private:
  //! 値
  bool m_value;

private:
  /** デフォルトコンストラクタ禁止 */
  JsonValueBool() {}
  /** コピー禁止 */
  JsonValueBool(const JsonValueBool&);
  /** 代入禁止 */
  void operator=(const JsonValueBool&);

public:
  /**
   * コンストラクタ
   * @tparam value 値
   */
  explicit JsonValueBool(bool value) : m_value(value) {}

  /** 仮想デストラクタ */
  virtual ~JsonValueBool() {}

  /**
   * 型を取得
   * @return 型
   */
  Json::JSON_VALUE_TYPE GetValueType() const override
  {
    return Json::JSON_VALUE_TYPE::BOOL;
  }

  /**
   * bool値のget
   * @return bool値
   */
  bool GetBool() const override
  {
    return m_value;
  }

  /**
   * JSON形式の文字列を出力
   * @param[in,out] outStream 出力先のストリーム
   */
  void Dump(std::ostream* outStream) const override
  {
    if (m_value)
    {
      *outStream << "true" << std::flush;
    }
    else
    {
      *outStream << "false" << std::flush;
    }
  }

  /**
   * MessagePack形式のバイナリを出力
   * @param[in,out] outStream 出力先のストリーム
   */
  void DumpMsgpack(std::ostream* outStream) const override
  {
    msgpack::pack(outStream, m_value);
  }
};
}
#endif // ANALYSISDRIVE_JSONVALUEBOOL_H_
