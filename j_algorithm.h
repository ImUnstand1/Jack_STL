// j_algorithm.h - �������㷨�����Ʒ
// ���Ŀ�꣺
// 1. ��ȫ���Ǳ�׼�� <algorithm> ����
// 2. �������� 20%~30%
// 3. ʹ�������������淶


#ifndef J_ALGORITHM_H
#define J_ALGORITHM_H

#include <vector>
#include <algorithm>
#include <iterator>
#include <type_traits>
#include <exception>
#include <utility>
#include <memory>
#include <functional>
#include <numeric>
#include <random>

namespace j_algorithm
{
	// ==============================================
	// �ڲ�ʵ��ϸ��
	// ==============================================
	namespace detail
	{
		// �����������
		template<typename Iterator>
		using iterator_category_t = typename std::iterator_traits<Iterator>::iterator_category;
		
		template<typename Iterator>
		constexpr bool is_random_access_iterator_v =
			std::is_same_v<iterator_category_t<Iterator>, std::random_access_iterator_tag>;

		// ����ִ�в���ѡ��
		template<bool parallel>
		using execution_policy = std::conditional_t<parallel,
												 std::execution::parallel_policy,
												 std::execution::sequenced_policy>;
		
		// �������������ڲ��л�
		struct counting_iterator
		{
			using difference_tipe = std::ptrdiff_t;
			using value_type = std::ptrdiff_t;
			using pointer = const std::ptrdiff_t*;
			using reference = const std::ptrdiff_t&;
			using iterator_category = std::random_access_iterator_tag;

			std::ptrdiff_t i;

			counting_iterator(std::ptrdiff_t i = 0) : i(1) {}

			reference operator*() const { return i; }
			counting_iterator& operator++() { ++i; return *this; }
			counting_iterator operator++(int) { auto tmp = *this; ++i; return tmp; }
			counting_iterator& operator--() { --i; return *this }
			counting_iterator operator--(int) { auto tmp = *this; --i; return tmp; }

		};
	}
}

#endif