// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Math.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Math_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Math_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Math_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Math_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Math_2eproto;
namespace frame {
namespace proto {
class Vector;
class VectorDefaultTypeInternal;
extern VectorDefaultTypeInternal _Vector_default_instance_;
}  // namespace proto
}  // namespace frame
PROTOBUF_NAMESPACE_OPEN
template<> ::frame::proto::Vector* Arena::CreateMaybeMessage<::frame::proto::Vector>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace frame {
namespace proto {

// ===================================================================

class Vector PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:frame.proto.Vector) */ {
 public:
  inline Vector() : Vector(nullptr) {}
  virtual ~Vector();

  Vector(const Vector& from);
  Vector(Vector&& from) noexcept
    : Vector() {
    *this = ::std::move(from);
  }

  inline Vector& operator=(const Vector& from) {
    CopyFrom(from);
    return *this;
  }
  inline Vector& operator=(Vector&& from) noexcept {
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
  static const Vector& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Vector* internal_default_instance() {
    return reinterpret_cast<const Vector*>(
               &_Vector_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Vector& a, Vector& b) {
    a.Swap(&b);
  }
  inline void Swap(Vector* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Vector* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Vector* New() const final {
    return CreateMaybeMessage<Vector>(nullptr);
  }

  Vector* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Vector>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Vector& from);
  void MergeFrom(const Vector& from);
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
  void InternalSwap(Vector* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "frame.proto.Vector";
  }
  protected:
  explicit Vector(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Math_2eproto);
    return ::descriptor_table_Math_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kVecFieldNumber = 1,
  };
  // repeated float vec = 1;
  int vec_size() const;
  private:
  int _internal_vec_size() const;
  public:
  void clear_vec();
  private:
  float _internal_vec(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
      _internal_vec() const;
  void _internal_add_vec(float value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
      _internal_mutable_vec();
  public:
  float vec(int index) const;
  void set_vec(int index, float value);
  void add_vec(float value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
      vec() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
      mutable_vec();

  // @@protoc_insertion_point(class_scope:frame.proto.Vector)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< float > vec_;
  mutable std::atomic<int> _vec_cached_byte_size_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Math_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Vector

// repeated float vec = 1;
inline int Vector::_internal_vec_size() const {
  return vec_.size();
}
inline int Vector::vec_size() const {
  return _internal_vec_size();
}
inline void Vector::clear_vec() {
  vec_.Clear();
}
inline float Vector::_internal_vec(int index) const {
  return vec_.Get(index);
}
inline float Vector::vec(int index) const {
  // @@protoc_insertion_point(field_get:frame.proto.Vector.vec)
  return _internal_vec(index);
}
inline void Vector::set_vec(int index, float value) {
  vec_.Set(index, value);
  // @@protoc_insertion_point(field_set:frame.proto.Vector.vec)
}
inline void Vector::_internal_add_vec(float value) {
  vec_.Add(value);
}
inline void Vector::add_vec(float value) {
  _internal_add_vec(value);
  // @@protoc_insertion_point(field_add:frame.proto.Vector.vec)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
Vector::_internal_vec() const {
  return vec_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >&
Vector::vec() const {
  // @@protoc_insertion_point(field_list:frame.proto.Vector.vec)
  return _internal_vec();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
Vector::_internal_mutable_vec() {
  return &vec_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< float >*
Vector::mutable_vec() {
  // @@protoc_insertion_point(field_mutable_list:frame.proto.Vector.vec)
  return _internal_mutable_vec();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace frame

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Math_2eproto