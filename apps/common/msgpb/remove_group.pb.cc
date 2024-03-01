// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: remove_group.proto

#include "remove_group.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace chatroom {
namespace msgpb {
class RemoveGroupDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<RemoveGroup> _instance;
} _RemoveGroup_default_instance_;
}  // namespace msgpb
}  // namespace chatroom
static void InitDefaultsscc_info_RemoveGroup_remove_5fgroup_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::chatroom::msgpb::_RemoveGroup_default_instance_;
    new (ptr) ::chatroom::msgpb::RemoveGroup();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::chatroom::msgpb::RemoveGroup::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_RemoveGroup_remove_5fgroup_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_RemoveGroup_remove_5fgroup_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_remove_5fgroup_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_remove_5fgroup_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_remove_5fgroup_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_remove_5fgroup_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::RemoveGroup, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::RemoveGroup, user_id_),
  PROTOBUF_FIELD_OFFSET(::chatroom::msgpb::RemoveGroup, group_id_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::chatroom::msgpb::RemoveGroup)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::chatroom::msgpb::_RemoveGroup_default_instance_),
};

const char descriptor_table_protodef_remove_5fgroup_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022remove_group.proto\022\016chatroom.msgpb\"0\n\013"
  "RemoveGroup\022\017\n\007user_id\030\001 \001(\005\022\020\n\010group_id"
  "\030\002 \001(\005b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_remove_5fgroup_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_remove_5fgroup_2eproto_sccs[1] = {
  &scc_info_RemoveGroup_remove_5fgroup_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_remove_5fgroup_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_remove_5fgroup_2eproto = {
  false, false, descriptor_table_protodef_remove_5fgroup_2eproto, "remove_group.proto", 94,
  &descriptor_table_remove_5fgroup_2eproto_once, descriptor_table_remove_5fgroup_2eproto_sccs, descriptor_table_remove_5fgroup_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_remove_5fgroup_2eproto::offsets,
  file_level_metadata_remove_5fgroup_2eproto, 1, file_level_enum_descriptors_remove_5fgroup_2eproto, file_level_service_descriptors_remove_5fgroup_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_remove_5fgroup_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_remove_5fgroup_2eproto)), true);
namespace chatroom {
namespace msgpb {

// ===================================================================

void RemoveGroup::InitAsDefaultInstance() {
}
class RemoveGroup::_Internal {
 public:
};

RemoveGroup::RemoveGroup(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:chatroom.msgpb.RemoveGroup)
}
RemoveGroup::RemoveGroup(const RemoveGroup& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&user_id_, &from.user_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&group_id_) -
    reinterpret_cast<char*>(&user_id_)) + sizeof(group_id_));
  // @@protoc_insertion_point(copy_constructor:chatroom.msgpb.RemoveGroup)
}

void RemoveGroup::SharedCtor() {
  ::memset(&user_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&group_id_) -
      reinterpret_cast<char*>(&user_id_)) + sizeof(group_id_));
}

RemoveGroup::~RemoveGroup() {
  // @@protoc_insertion_point(destructor:chatroom.msgpb.RemoveGroup)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void RemoveGroup::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void RemoveGroup::ArenaDtor(void* object) {
  RemoveGroup* _this = reinterpret_cast< RemoveGroup* >(object);
  (void)_this;
}
void RemoveGroup::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void RemoveGroup::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const RemoveGroup& RemoveGroup::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_RemoveGroup_remove_5fgroup_2eproto.base);
  return *internal_default_instance();
}


void RemoveGroup::Clear() {
// @@protoc_insertion_point(message_clear_start:chatroom.msgpb.RemoveGroup)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&user_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&group_id_) -
      reinterpret_cast<char*>(&user_id_)) + sizeof(group_id_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* RemoveGroup::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // int32 user_id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          user_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // int32 group_id = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          group_id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* RemoveGroup::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:chatroom.msgpb.RemoveGroup)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 user_id = 1;
  if (this->user_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_user_id(), target);
  }

  // int32 group_id = 2;
  if (this->group_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_group_id(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:chatroom.msgpb.RemoveGroup)
  return target;
}

size_t RemoveGroup::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:chatroom.msgpb.RemoveGroup)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 user_id = 1;
  if (this->user_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_user_id());
  }

  // int32 group_id = 2;
  if (this->group_id() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
        this->_internal_group_id());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RemoveGroup::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:chatroom.msgpb.RemoveGroup)
  GOOGLE_DCHECK_NE(&from, this);
  const RemoveGroup* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<RemoveGroup>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:chatroom.msgpb.RemoveGroup)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:chatroom.msgpb.RemoveGroup)
    MergeFrom(*source);
  }
}

void RemoveGroup::MergeFrom(const RemoveGroup& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:chatroom.msgpb.RemoveGroup)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.user_id() != 0) {
    _internal_set_user_id(from._internal_user_id());
  }
  if (from.group_id() != 0) {
    _internal_set_group_id(from._internal_group_id());
  }
}

void RemoveGroup::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:chatroom.msgpb.RemoveGroup)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RemoveGroup::CopyFrom(const RemoveGroup& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:chatroom.msgpb.RemoveGroup)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RemoveGroup::IsInitialized() const {
  return true;
}

void RemoveGroup::InternalSwap(RemoveGroup* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(RemoveGroup, group_id_)
      + sizeof(RemoveGroup::group_id_)
      - PROTOBUF_FIELD_OFFSET(RemoveGroup, user_id_)>(
          reinterpret_cast<char*>(&user_id_),
          reinterpret_cast<char*>(&other->user_id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata RemoveGroup::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace msgpb
}  // namespace chatroom
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::chatroom::msgpb::RemoveGroup* Arena::CreateMaybeMessage< ::chatroom::msgpb::RemoveGroup >(Arena* arena) {
  return Arena::CreateMessageInternal< ::chatroom::msgpb::RemoveGroup >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
