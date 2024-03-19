// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: datapb/friend_message_field.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_datapb_2ffriend_5fmessage_5ffield_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_datapb_2ffriend_5fmessage_5ffield_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
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
#define PROTOBUF_INTERNAL_EXPORT_datapb_2ffriend_5fmessage_5ffield_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_datapb_2ffriend_5fmessage_5ffield_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_datapb_2ffriend_5fmessage_5ffield_2eproto;
namespace chatroom {
namespace datapb {
class FriendMessageField;
class FriendMessageFieldDefaultTypeInternal;
extern FriendMessageFieldDefaultTypeInternal _FriendMessageField_default_instance_;
}  // namespace datapb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> ::chatroom::datapb::FriendMessageField* Arena::CreateMaybeMessage<::chatroom::datapb::FriendMessageField>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace chatroom {
namespace datapb {

// ===================================================================

class FriendMessageField PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:chatroom.datapb.FriendMessageField) */ {
 public:
  inline FriendMessageField() : FriendMessageField(nullptr) {};
  virtual ~FriendMessageField();

  FriendMessageField(const FriendMessageField& from);
  FriendMessageField(FriendMessageField&& from) noexcept
    : FriendMessageField() {
    *this = ::std::move(from);
  }

  inline FriendMessageField& operator=(const FriendMessageField& from) {
    CopyFrom(from);
    return *this;
  }
  inline FriendMessageField& operator=(FriendMessageField&& from) noexcept {
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
  static const FriendMessageField& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FriendMessageField* internal_default_instance() {
    return reinterpret_cast<const FriendMessageField*>(
               &_FriendMessageField_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FriendMessageField& a, FriendMessageField& b) {
    a.Swap(&b);
  }
  inline void Swap(FriendMessageField* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FriendMessageField* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FriendMessageField* New() const final {
    return CreateMaybeMessage<FriendMessageField>(nullptr);
  }

  FriendMessageField* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FriendMessageField>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FriendMessageField& from);
  void MergeFrom(const FriendMessageField& from);
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
  void InternalSwap(FriendMessageField* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "chatroom.datapb.FriendMessageField";
  }
  protected:
  explicit FriendMessageField(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_datapb_2ffriend_5fmessage_5ffield_2eproto);
    return ::descriptor_table_datapb_2ffriend_5fmessage_5ffield_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMsgsFieldNumber = 1,
  };
  // repeated string msgs = 1;
  int msgs_size() const;
  private:
  int _internal_msgs_size() const;
  public:
  void clear_msgs();
  const std::string& msgs(int index) const;
  std::string* mutable_msgs(int index);
  void set_msgs(int index, const std::string& value);
  void set_msgs(int index, std::string&& value);
  void set_msgs(int index, const char* value);
  void set_msgs(int index, const char* value, size_t size);
  std::string* add_msgs();
  void add_msgs(const std::string& value);
  void add_msgs(std::string&& value);
  void add_msgs(const char* value);
  void add_msgs(const char* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& msgs() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_msgs();
  private:
  const std::string& _internal_msgs(int index) const;
  std::string* _internal_add_msgs();
  public:

  // @@protoc_insertion_point(class_scope:chatroom.datapb.FriendMessageField)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> msgs_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_datapb_2ffriend_5fmessage_5ffield_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FriendMessageField

// repeated string msgs = 1;
inline int FriendMessageField::_internal_msgs_size() const {
  return msgs_.size();
}
inline int FriendMessageField::msgs_size() const {
  return _internal_msgs_size();
}
inline void FriendMessageField::clear_msgs() {
  msgs_.Clear();
}
inline std::string* FriendMessageField::add_msgs() {
  // @@protoc_insertion_point(field_add_mutable:chatroom.datapb.FriendMessageField.msgs)
  return _internal_add_msgs();
}
inline const std::string& FriendMessageField::_internal_msgs(int index) const {
  return msgs_.Get(index);
}
inline const std::string& FriendMessageField::msgs(int index) const {
  // @@protoc_insertion_point(field_get:chatroom.datapb.FriendMessageField.msgs)
  return _internal_msgs(index);
}
inline std::string* FriendMessageField::mutable_msgs(int index) {
  // @@protoc_insertion_point(field_mutable:chatroom.datapb.FriendMessageField.msgs)
  return msgs_.Mutable(index);
}
inline void FriendMessageField::set_msgs(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:chatroom.datapb.FriendMessageField.msgs)
  msgs_.Mutable(index)->assign(value);
}
inline void FriendMessageField::set_msgs(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:chatroom.datapb.FriendMessageField.msgs)
  msgs_.Mutable(index)->assign(std::move(value));
}
inline void FriendMessageField::set_msgs(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  msgs_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:chatroom.datapb.FriendMessageField.msgs)
}
inline void FriendMessageField::set_msgs(int index, const char* value, size_t size) {
  msgs_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:chatroom.datapb.FriendMessageField.msgs)
}
inline std::string* FriendMessageField::_internal_add_msgs() {
  return msgs_.Add();
}
inline void FriendMessageField::add_msgs(const std::string& value) {
  msgs_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:chatroom.datapb.FriendMessageField.msgs)
}
inline void FriendMessageField::add_msgs(std::string&& value) {
  msgs_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:chatroom.datapb.FriendMessageField.msgs)
}
inline void FriendMessageField::add_msgs(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  msgs_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:chatroom.datapb.FriendMessageField.msgs)
}
inline void FriendMessageField::add_msgs(const char* value, size_t size) {
  msgs_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:chatroom.datapb.FriendMessageField.msgs)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
FriendMessageField::msgs() const {
  // @@protoc_insertion_point(field_list:chatroom.datapb.FriendMessageField.msgs)
  return msgs_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
FriendMessageField::mutable_msgs() {
  // @@protoc_insertion_point(field_mutable_list:chatroom.datapb.FriendMessageField.msgs)
  return &msgs_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace datapb
}  // namespace chatroom

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_datapb_2ffriend_5fmessage_5ffield_2eproto