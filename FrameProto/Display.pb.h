// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Display.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Display_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Display_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Texture.pb.h"
#include "Effect.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Display_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Display_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Display_2eproto;
namespace frame {
namespace proto {
class Display;
class DisplayDefaultTypeInternal;
extern DisplayDefaultTypeInternal _Display_default_instance_;
}  // namespace proto
}  // namespace frame
PROTOBUF_NAMESPACE_OPEN
template<> ::frame::proto::Display* Arena::CreateMaybeMessage<::frame::proto::Display>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace frame {
namespace proto {

// ===================================================================

class Display PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:frame.proto.Display) */ {
 public:
  inline Display() : Display(nullptr) {};
  virtual ~Display();

  Display(const Display& from);
  Display(Display&& from) noexcept
    : Display() {
    *this = ::std::move(from);
  }

  inline Display& operator=(const Display& from) {
    CopyFrom(from);
    return *this;
  }
  inline Display& operator=(Display&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Display& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Display* internal_default_instance() {
    return reinterpret_cast<const Display*>(
               &_Display_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Display& a, Display& b) {
    a.Swap(&b);
  }
  inline void Swap(Display* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Display* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Display* New() const final {
    return CreateMaybeMessage<Display>(nullptr);
  }

  Display* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Display>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Display& from);
  void MergeFrom(const Display& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Display* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "frame.proto.Display";
  }
  protected:
  explicit Display(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Display_2eproto);
    return ::descriptor_table_Display_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kInTexturesFieldNumber = 1,
    kOutTexturesFieldNumber = 2,
    kTexturesFieldNumber = 10,
    kEffectsFieldNumber = 11,
  };
  // repeated string in_textures = 1;
  int in_textures_size() const;
  private:
  int _internal_in_textures_size() const;
  public:
  void clear_in_textures();
  const std::string& in_textures(int index) const;
  std::string* mutable_in_textures(int index);
  void set_in_textures(int index, const std::string& value);
  void set_in_textures(int index, std::string&& value);
  void set_in_textures(int index, const char* value);
  void set_in_textures(int index, const char* value, size_t size);
  std::string* add_in_textures();
  void add_in_textures(const std::string& value);
  void add_in_textures(std::string&& value);
  void add_in_textures(const char* value);
  void add_in_textures(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& in_textures() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_in_textures();
  private:
  const std::string& _internal_in_textures(int index) const;
  std::string* _internal_add_in_textures();
  public:

  // repeated string out_textures = 2;
  int out_textures_size() const;
  private:
  int _internal_out_textures_size() const;
  public:
  void clear_out_textures();
  const std::string& out_textures(int index) const;
  std::string* mutable_out_textures(int index);
  void set_out_textures(int index, const std::string& value);
  void set_out_textures(int index, std::string&& value);
  void set_out_textures(int index, const char* value);
  void set_out_textures(int index, const char* value, size_t size);
  std::string* add_out_textures();
  void add_out_textures(const std::string& value);
  void add_out_textures(std::string&& value);
  void add_out_textures(const char* value);
  void add_out_textures(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& out_textures() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_out_textures();
  private:
  const std::string& _internal_out_textures(int index) const;
  std::string* _internal_add_out_textures();
  public:

  // repeated .frame.proto.Texture textures = 10;
  int textures_size() const;
  private:
  int _internal_textures_size() const;
  public:
  void clear_textures();
  ::frame::proto::Texture* mutable_textures(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame::proto::Texture >*
      mutable_textures();
  private:
  const ::frame::proto::Texture& _internal_textures(int index) const;
  ::frame::proto::Texture* _internal_add_textures();
  public:
  const ::frame::proto::Texture& textures(int index) const;
  ::frame::proto::Texture* add_textures();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame::proto::Texture >&
      textures() const;

  // repeated .frame.proto.Effect effects = 11;
  int effects_size() const;
  private:
  int _internal_effects_size() const;
  public:
  void clear_effects();
  ::frame::proto::Effect* mutable_effects(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame::proto::Effect >*
      mutable_effects();
  private:
  const ::frame::proto::Effect& _internal_effects(int index) const;
  ::frame::proto::Effect* _internal_add_effects();
  public:
  const ::frame::proto::Effect& effects(int index) const;
  ::frame::proto::Effect* add_effects();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame::proto::Effect >&
      effects() const;

  // @@protoc_insertion_point(class_scope:frame.proto.Display)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> in_textures_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> out_textures_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame::proto::Texture > textures_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame::proto::Effect > effects_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Display_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Display

// repeated string in_textures = 1;
inline int Display::_internal_in_textures_size() const {
  return in_textures_.size();
}
inline int Display::in_textures_size() const {
  return _internal_in_textures_size();
}
inline void Display::clear_in_textures() {
  in_textures_.Clear();
}
inline std::string* Display::add_in_textures() {
  // @@protoc_insertion_point(field_add_mutable:frame.proto.Display.in_textures)
  return _internal_add_in_textures();
}
inline const std::string& Display::_internal_in_textures(int index) const {
  return in_textures_.Get(index);
}
inline const std::string& Display::in_textures(int index) const {
  // @@protoc_insertion_point(field_get:frame.proto.Display.in_textures)
  return _internal_in_textures(index);
}
inline std::string* Display::mutable_in_textures(int index) {
  // @@protoc_insertion_point(field_mutable:frame.proto.Display.in_textures)
  return in_textures_.Mutable(index);
}
inline void Display::set_in_textures(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:frame.proto.Display.in_textures)
  in_textures_.Mutable(index)->assign(value);
}
inline void Display::set_in_textures(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:frame.proto.Display.in_textures)
  in_textures_.Mutable(index)->assign(std::move(value));
}
inline void Display::set_in_textures(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  in_textures_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:frame.proto.Display.in_textures)
}
inline void Display::set_in_textures(int index, const char* value, size_t size) {
  in_textures_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:frame.proto.Display.in_textures)
}
inline std::string* Display::_internal_add_in_textures() {
  return in_textures_.Add();
}
inline void Display::add_in_textures(const std::string& value) {
  in_textures_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:frame.proto.Display.in_textures)
}
inline void Display::add_in_textures(std::string&& value) {
  in_textures_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:frame.proto.Display.in_textures)
}
inline void Display::add_in_textures(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  in_textures_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:frame.proto.Display.in_textures)
}
inline void Display::add_in_textures(const char* value, size_t size) {
  in_textures_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:frame.proto.Display.in_textures)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
Display::in_textures() const {
  // @@protoc_insertion_point(field_list:frame.proto.Display.in_textures)
  return in_textures_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
Display::mutable_in_textures() {
  // @@protoc_insertion_point(field_mutable_list:frame.proto.Display.in_textures)
  return &in_textures_;
}

// repeated string out_textures = 2;
inline int Display::_internal_out_textures_size() const {
  return out_textures_.size();
}
inline int Display::out_textures_size() const {
  return _internal_out_textures_size();
}
inline void Display::clear_out_textures() {
  out_textures_.Clear();
}
inline std::string* Display::add_out_textures() {
  // @@protoc_insertion_point(field_add_mutable:frame.proto.Display.out_textures)
  return _internal_add_out_textures();
}
inline const std::string& Display::_internal_out_textures(int index) const {
  return out_textures_.Get(index);
}
inline const std::string& Display::out_textures(int index) const {
  // @@protoc_insertion_point(field_get:frame.proto.Display.out_textures)
  return _internal_out_textures(index);
}
inline std::string* Display::mutable_out_textures(int index) {
  // @@protoc_insertion_point(field_mutable:frame.proto.Display.out_textures)
  return out_textures_.Mutable(index);
}
inline void Display::set_out_textures(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:frame.proto.Display.out_textures)
  out_textures_.Mutable(index)->assign(value);
}
inline void Display::set_out_textures(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:frame.proto.Display.out_textures)
  out_textures_.Mutable(index)->assign(std::move(value));
}
inline void Display::set_out_textures(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  out_textures_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:frame.proto.Display.out_textures)
}
inline void Display::set_out_textures(int index, const char* value, size_t size) {
  out_textures_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:frame.proto.Display.out_textures)
}
inline std::string* Display::_internal_add_out_textures() {
  return out_textures_.Add();
}
inline void Display::add_out_textures(const std::string& value) {
  out_textures_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:frame.proto.Display.out_textures)
}
inline void Display::add_out_textures(std::string&& value) {
  out_textures_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:frame.proto.Display.out_textures)
}
inline void Display::add_out_textures(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  out_textures_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:frame.proto.Display.out_textures)
}
inline void Display::add_out_textures(const char* value, size_t size) {
  out_textures_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:frame.proto.Display.out_textures)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
Display::out_textures() const {
  // @@protoc_insertion_point(field_list:frame.proto.Display.out_textures)
  return out_textures_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
Display::mutable_out_textures() {
  // @@protoc_insertion_point(field_mutable_list:frame.proto.Display.out_textures)
  return &out_textures_;
}

// repeated .frame.proto.Texture textures = 10;
inline int Display::_internal_textures_size() const {
  return textures_.size();
}
inline int Display::textures_size() const {
  return _internal_textures_size();
}
inline ::frame::proto::Texture* Display::mutable_textures(int index) {
  // @@protoc_insertion_point(field_mutable:frame.proto.Display.textures)
  return textures_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame::proto::Texture >*
Display::mutable_textures() {
  // @@protoc_insertion_point(field_mutable_list:frame.proto.Display.textures)
  return &textures_;
}
inline const ::frame::proto::Texture& Display::_internal_textures(int index) const {
  return textures_.Get(index);
}
inline const ::frame::proto::Texture& Display::textures(int index) const {
  // @@protoc_insertion_point(field_get:frame.proto.Display.textures)
  return _internal_textures(index);
}
inline ::frame::proto::Texture* Display::_internal_add_textures() {
  return textures_.Add();
}
inline ::frame::proto::Texture* Display::add_textures() {
  // @@protoc_insertion_point(field_add:frame.proto.Display.textures)
  return _internal_add_textures();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame::proto::Texture >&
Display::textures() const {
  // @@protoc_insertion_point(field_list:frame.proto.Display.textures)
  return textures_;
}

// repeated .frame.proto.Effect effects = 11;
inline int Display::_internal_effects_size() const {
  return effects_.size();
}
inline int Display::effects_size() const {
  return _internal_effects_size();
}
inline ::frame::proto::Effect* Display::mutable_effects(int index) {
  // @@protoc_insertion_point(field_mutable:frame.proto.Display.effects)
  return effects_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame::proto::Effect >*
Display::mutable_effects() {
  // @@protoc_insertion_point(field_mutable_list:frame.proto.Display.effects)
  return &effects_;
}
inline const ::frame::proto::Effect& Display::_internal_effects(int index) const {
  return effects_.Get(index);
}
inline const ::frame::proto::Effect& Display::effects(int index) const {
  // @@protoc_insertion_point(field_get:frame.proto.Display.effects)
  return _internal_effects(index);
}
inline ::frame::proto::Effect* Display::_internal_add_effects() {
  return effects_.Add();
}
inline ::frame::proto::Effect* Display::add_effects() {
  // @@protoc_insertion_point(field_add:frame.proto.Display.effects)
  return _internal_add_effects();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::frame::proto::Effect >&
Display::effects() const {
  // @@protoc_insertion_point(field_list:frame.proto.Display.effects)
  return effects_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace frame

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Display_2eproto
